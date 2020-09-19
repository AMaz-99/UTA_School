"""
CSE 3313 - 001
Homework 06 Question 3
@author: Aamir Mazumdar 1001523593

"""

import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf

def processFile(fn, offset) :
    data, samplerate = sf.read(fn)
    fft_data = np.fft.fft(data)
    midpoint = len(fft_data)//2
    copy = np.copy(fft_data)       # copy is going to be the array where
    copy[midpoint] = 0          #   the noise is filtered out
    for i in range(offset):
        copy[midpoint + i] = 0
        copy[midpoint - i] = 0
    freq_arr = np.fft.ifft(copy)
    result_file = np.real(freq_arr)
    sf.write('cleanMusic.wav', result_file, samplerate)
    # plt.plot(np.arange(0, len(fft_data), 1), abs(fft_data))
    # plt.show()
    # seeOrg = fft_data[midpoint - 100: midpoint + 100:]
    # seeAlt = copy[midpoint - 100: midpoint + 100:]
    graph(copy, fft_data)


# creates the graphs for comparison
def graph(altered, original):
    x = np.arange(0, len(original), 1)
    plt.subplot(1, 2, 1)
    plt.plot(x, abs(original))
    plt.title('Magnitude of the Original')
#    plt.xlim(len(original) // 2 - (offset + 5000), len(original) // 2 + (offset + 5000))

    plt.subplot(1, 2, 2)
    plt.plot(x, abs(altered))
    plt.title('Magnitude of the Altered')
#    plt.xlim(len(original) // 2 - (offset + 5000), len(original) // 2 + (offset + 5000))
    plt.show()

##############  main  ##############
if __name__ == "__main__":
    filename = "P_9_2.wav"
    offset = 15000

    # this function should be how your code knows the name of
    #   the file to process and the offset to use
    processFile(filename, offset)

