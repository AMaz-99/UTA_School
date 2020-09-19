"""
CSE 3313 - 001
Homework 04 Question 3
@author: Aamir Mazumdar 1001523593

"""

import numpy as np
import matplotlib.pyplot as plt
from scipy import ndimage

lpf = np.repeat(.1, 10)
hpf = np.array([1, -1])


def printImage(image):
    imgLPF = filter(image, len(image), lpf)
    imgHPF = filter(image, len(image), hpf)
    show_gray_img(image, 'Original Array')
    show_gray_img(imgLPF, 'Low Pass Application')
    show_gray_img(imgHPF, 'High Pass Application')

def filter(image, rows, ftype):
    n = range(rows)
    result = []
    for i in n:
        temp = image[i, 0:-1]
        temp = np.array(temp)
        buffer = np.convolve(temp, ftype)
        if i == 0:
            result = np.append(result, buffer)
        else:
            result = np.vstack((result, buffer))

    return result

def show_gray_img(img, title):
    plt.imshow(img, cmap='gray')
    plt.title(title)
    plt.show()

def DBimage(image):
    i = len(image)
    medianimg = ndimage.median_filter(image, 5)
    lpfimg = filter(image, i, lpf)
    show_gray_img(image, 'Original')
    show_gray_img(lpfimg, 'LPF Application')
    show_gray_img(medianimg, 'Median Filter')


def main():
    boat = plt.imread('boat.512.tiff')
    clock = plt.imread('clock-5.1.12.tiff')
    man = plt.imread('man-5.3.01.tiff')
    tank = plt.imread('tank-7.1.07.tiff')
    db = plt.imread('darinGrayNoise.jpg')
    printImage(boat)
    printImage(clock)
    printImage(man)
    printImage(tank)
    DBimage(db)

if __name__ == '__main__':
    main()
