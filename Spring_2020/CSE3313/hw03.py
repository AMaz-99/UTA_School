"""
CSE 3313 - 001
Homework 03
@author: Aamir Mazumdar 1001523593

"""



import numpy as np

p0 = np.ones(10)
p1 = np.append(np.ones(5), -1 * np.ones(5))
p0_norm = np.linalg.norm(p0)
p1_norm = np.linalg.norm(p1)

def convertBinarytoChar(array):
    temp = int("".join(str(x) for x in array), 2)
    result = chr(temp)
    return result

def csvSorter (array):
    index, i = 0, 0
    buffer_bit = [0] * 8
    result = []
    while (i < (len(array) // 8)):
        buffer_array = array[8*i:((i+1) * 8), :]
        while(index < len(buffer_array)):
            buffer = buffer_array[index, :]
            temp0 = np.abs((np.dot(p0, buffer) / (p0_norm * np.linalg.norm(buffer))))
            temp1 = np.abs((np.dot(p1, buffer) / (p1_norm * np.linalg.norm(buffer))))
            if temp0 > temp1:
               buffer_bit[index] = 0
            else:
                buffer_bit[index] = 1
            index += 1
        i += 1
        index = 0
#        print(convertBinarytoChar(buffer_bit)) Debugging
        result.append(convertBinarytoChar(buffer_bit))
    return ''.join(result)

def main():
    buffer_store = np.loadtxt('data-communications.csv', delimiter=',')
    store = np.reshape(buffer_store, (len(buffer_store) // 10, 10))
    message = csvSorter(store)
    print(message)


if __name__ == '__main__':
    main()


