"""
CSE 3313 - 001
Homework 07 Question 3
@author: Aamir Mazumdar 1001523593

"""

from scipy.signal import freqz
import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import spectrogram


row_freq = [697, 770, 852, 941]
column_freq = [1209, 1336, 1477]
keypad_index = [['1', '2', '3'],
                ['4', '5', '6'],
                ['7', '8', '9'],
                ['*', '0', '#']
                ]


def determineKey(data, L, fs):
    row_index = findindex(data, L, fs, row_freq)
    colm_index = findindex(data, L, fs, column_freq)
    return keypad_index[row_index][colm_index]


def findindex(data, L, fs, axis):
    index, mean = 0, 0
    n = np.arange(0, L) # weights indices
    m = len(axis)       # length of the frequency table
    for i in range(m):
        bandpass = []
        for j in n:
            r = (2 / L) * \
                (np.cos(2 * np.pi * j * axis[i] / fs))
            bandpass = np.append(bandpass, r)
        temp = np.convolve(data, bandpass)
        temp_mean = np.mean(np.square(temp))
        if temp_mean > mean: # checks for the highest average
            mean = temp_mean
            index = i
    return index


def plotSpectrogram(file, fs):
    f, t, Sxx = spectrogram(file, fs)
    plt.pcolormesh(t, f, Sxx)
    plt.ylabel('Frequency [Hz]')
    plt.xlabel('Time [sec]')
    plt.show()


def plotFreqResponse(L, fs):
    freq = []
    freq = np.append(freq, row_freq)
    freq = np.append(freq, column_freq)
    n = np.arange(0, L)
    m = len(freq)
    fig, ax = plt.subplots()  # plots the bandpass coefficients
                              #     for all frequencies
    for i in range(m):
        bandpass = []
        for j in n:
            r = (2 / L) * \
                (np.cos(2 * np.pi * j * freq[i] / fs))
            bandpass = np.append(bandpass, r)
        x, y = freqz(bandpass, 1, fs = fs)
        ax.plot(x, abs(y))
    plt.title('Frequency Responses of the Filters')
    plt.xlabel('Herz')
    plt.show()


def processTones(name, L, fs, samplesPerTone):
    file = np.loadtxt(name, delimiter=',') # loads the csv into an array
    result = ''
    data = np.reshape(file, (-1, samplesPerTone))  # reshapes each row to a key
    n = len(data)  # find the rows of data
    for i in range(n):
        temp = determineKey(data[i, :], L, fs)  # gets the key
        result += temp  # adds to result
    plotFreqResponse(L, fs)
    plotSpectrogram(file, fs)
    return result


#############  main  #############
if __name__ == "__main__":
    filename = "tones.csv"  # name of file to process
    L = 64  # filter length
    fs = 8000  # sampling rate
    samplesPerTone = 4000  # 4000 samples per tone,
    #    NOT the total number of samples per signal

    # returns string of telephone buttons corresponding to tones
    phoneNumber = processTones(filename, L, fs, samplesPerTone)

    print(phoneNumber)
