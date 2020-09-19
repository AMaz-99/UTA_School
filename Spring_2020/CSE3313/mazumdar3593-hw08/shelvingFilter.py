"""
CSE 3313 - 001
Homework 08 Question 1
@author: Aamir Mazumdar 1001523593


**Misspelling of Lambda to Lamda is on purpose **
"""

import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf


def calcLamda(mu, gain, fc, fs):
    tangent = np.tan((2 * np.pi * fc / fs) / 2)
    frac = 4 / (1 + mu)
    numerator = 1 - (frac * tangent)
    denom = 1 + (frac * tangent)
    return numerator/denom


def calcUfunc(x, lamda, alpha):
    buffer = []
    for i in range(len(x)):
        if i - 1 < 0:
            buffer = np.append(buffer, alpha * x[i])
        buffer = np.append(buffer, alpha * (x[i] + x[i - 1]) + \
                           (lamda * buffer[i - 1]))
    return buffer


def calcYfunc(x, mu, u):
    buffer = []
    for i in range(len(x)):
        value = x[i] + ((mu - 1) * u[i])
        buffer = np.append(buffer, value)
    return buffer


def graphfft(original, altered, fs):
    fftOriginal = np.fft.fft(original)
    fftAltered  = np.fft.fft(altered)
#    x = np.arange(0, len(original) / 4)
    x = np.fft.fftfreq(len(fftOriginal), 1 / fs)
    maxOrig = np.amax(abs(fftOriginal))
    maxAlt = np.amax(abs(fftAltered))
    if maxAlt > maxOrig:
        max = maxAlt + 100
    else:
        max = maxOrig + 100
    plt.subplot(1, 2, 1)
    plt.plot(x[0:len(fftOriginal) // 4], abs(fftOriginal[0:len(fftOriginal)//4]))
    plt.title('Original Signal')
    plt.xlabel('Hz')
    plt.ylim(bottom=0, top=max)
    plt.subplot(1, 2, 2)
    plt.plot(x[0:len(fftOriginal) // 4], abs(fftAltered[0:len(fftOriginal)//4]))
    plt.title('Filtered Signal')
    plt.xlabel('Hz')
    plt.ylim(bottom=0, top=max)
    plt.show()


def applyShelvingFilter(inName, outName, g, fc) :
    x, fs = sf.read(inName)  # x(n) and the sampling frequency
    mu = 10 ** g  # computers mu
    lamda = calcLamda(mu, g, fc, fs)  # calculate the coefficients
    alpha = (1 - lamda) / 2  # calculate the coefficients
    u = calcUfunc(x, lamda, alpha)  # calculate u of n function
    y = calcYfunc(x, mu, u)
    sf.write(outName, y, fs)
    graphfft(x, y, fs)


##########################  main  ##########################
if __name__ == "__main__" :
    inName = "P_9_1.wav"
    gain = -10  # can be positive or negative
                # WARNING: small positive values can greatly amplify the sounds
    cutoff = 300
    outName = "shelvingOutput.wav"
    applyShelvingFilter(inName, outName, gain, cutoff)
