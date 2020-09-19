"""
CSE 3313 - 001
Homework 04
@author: Aamir Mazumdar 1001523593

"""

import numpy as np
import matplotlib.pyplot as plt

fsample = 2000
L = 21

def LPF(array):
    fcutoff = 50
    ft = fcutoff/fsample
    M = L - 1
    weight = []
    for n in range(21): #Calculate the weights
        if n == M/2:
            weight.append(2*ft)
        else:
            i = 2 * np.pi * ft * (n - (M / 2))
            k = np.pi * (n - (M / 2))
            r = np.sin(i)/k
            weight.append(r)
    result = np.convolve(array, weight)
    t = np.arange(0, 2000)
    passed_through = np.sin(2 * np.pi * 4 * t/fsample)
    graphLPF(array, passed_through, result[:2000], t)
def HPF(array):
    fcutoff = 280
    ft = fcutoff/fsample
    M = L - 1
    weight = []
    for n in range(21): #Calculate the weights
        if n == M/2:
            weight.append(1 - 2*ft)
        else:
            i = 2 * np.pi * ft * (n - (M / 2))
            k = np.pi * (n - (M / 2))
            r = -1 * (np.sin(i)/k)
            weight.append(r)
    result = np.convolve(array, weight)
    t = np.arange(0, 100)
    passed_through = np.cos(2 * np.pi * 330 * t/fsample)
    graphHPF(array[:100], passed_through, result[:100], t)

def graphLPF(array1, array2, array3, xval):
    # let array1 be the original, array 2 be the pass through signal,
    # and array 3 be the application of the filter
    plt.subplot(3, 1, 1)
    plt.plot(xval, array1)
    plt.title("Original Signal")
    plt.subplot(3, 1, 2)
    plt.plot(xval, array2)
    plt.title("4 Hz Passed Through Signal")
    plt.subplot(3, 1, 3)
    plt.plot(xval, array3)
    plt.title("Application of Filter")
    plt.tight_layout()
    plt.show()

def graphHPF(array1, array2, array3, xval):
    # let array1 be the original, array 2 be the pass through signal,
    # and array 3 be the application of the filter
    plt.subplot(3, 1, 1)
    plt.plot(xval, array1)
    plt.title("Original Signal")
    plt.subplot(3, 1, 2)
    plt.plot(xval, array2)
    plt.title("330 HzPassed Through Signal")
    plt.subplot(3, 1, 3)
    plt.plot(xval, array3)
    plt.title("Application of Filter")
    plt.tight_layout()
    plt.show()


def main():
    buffer_store = np.loadtxt('data-filtering.csv', delimiter=',')
    LPF(buffer_store)
    HPF(buffer_store)



if __name__ == '__main__':
    main()

