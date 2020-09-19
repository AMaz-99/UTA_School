"""
CSE 3313 - 001
Homework 05 Question 2
@author: Aamir Mazumdar 1001523593

"""

import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import freqz
import soundfile as sf

L = 101
M = L - 1


def low_pass_filter(fsample: int):
    fcutoff = 7500
    ft = fcutoff/fsample
    weight = []
    n = np.arange(0, L//2, 1)
    r = np.sin(2 * np.pi * ft * (n - (M / 2)))/(np.pi * (n - (M / 2)))
    weight = np.append(weight, r)
    if L % 2 == 1:
        flip = np.flip(weight)
        weight = np.append(weight, 2 * ft)
        weight = np.append(weight, flip)
    else:
        weight = np.append(weight, np.flip(weight))
    # for n in range(L): #Calculate the weights
    #     if n == M/2:
    #         weight.append(2*ft)
    #     else:
    #         i = 2 * np.pi * ft * (n - (M / 2))
    #         k = np.pi * (n - (M / 2))
    #         r = np.sin(i)/k
    #         weight.append(r)
    return weight


def hamming_window(array: int):
    n = np.arange(0, L, 1)
    hamming = .54 - .46 * np.cos(2 * np.pi * n / M)
    return hamming


def graph(array: int, fsample: int):
    lpf = low_pass_filter(fsample)
    ham = hamming_window(array)
    hknot = np.multiply(lpf, ham)
    x, y = freqz(lpf, 1)
    w, z = freqz(hknot, 1)
    fig, ax = plt.subplots()
    ax.plot(x, abs(y), label = 'Original')
    ax.plot(w, abs(z), label = 'Hamming Window')
    ax.axis('equal')
    plt.title('Frequency Response')
    leg = ax.legend(loc = 'lower left')
    plt.show()
    return np.convolve(hknot, array)


def main():
    data, samplerate = sf.read('P_9_2.wav')
    result = graph(data, samplerate)
    sf.write('cleanMusic.wav', result, samplerate )


if __name__ == '__main__':
    main()