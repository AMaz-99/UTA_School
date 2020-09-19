"""
CSE 3313 - 001
Homework 06 Question 4
@author: Aamir Mazumdar 1001523593

"""

import numpy as np
import matplotlib.pyplot as plt

from skimage.feature import match_template


def findImage(mainImage, template):
    grayMain = grayScale(plt.imread(mainImage))
    grayTemp = np.array(grayScale(plt.imread(template)))
    show_gray_img(grayMain, 'Main')
    show_gray_img(grayTemp, 'Template')
    result = np.array(match_template(grayMain, grayTemp))
    ij = np.unravel_index(np.argmax(result), result.shape)
    x, y = ij[::-1]
    temp_x, temp_y = grayTemp.shape
    # matched = plt.subplot(1,1,1)
    # matched.imshow(grayMain, cmap='gray')
    # matched.set_title('Matched')
    # height, width = grayTemp.shape
    # rect = plt.Rectangle((x, y), width, height, facecolor='black')
    # matched.add_patch(rect)
    # plt.show()
    overlayImage = np.copy(grayMain)
    overlayImage[y: y + temp_y, x: x + temp_x] = 0
    show_gray_img(overlayImage, 'Black Pixel Marked')
    return x, y


def grayScale(image):
    return np.dot(image[..., :3], [.2989, .5870, .1140])


def show_gray_img(img, title):
    plt.imshow(img, cmap='gray')
    plt.title(title)
    plt.show()


#############  main  #############
# this function should be how your code knows the names of
#   the images to process
# it will return the coordinates of where the template best fits

if __name__ == "__main__":
    mainImage = "ERBwideColorSmall.jpg"
    template = "ERBwideTemplate.jpg"
    r, c = findImage(mainImage, template)

    print("coordinates of match = (%d, %d)" % (r, c))
