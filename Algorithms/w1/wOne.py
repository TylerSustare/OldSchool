import random
import time

def inPlaceInsertionSort(numbers):
    i = 1
    while i < len(numbers):
        j = i
        k = i - 1
        while k > 0 and numbers[j] > numbers[k]:
            temp = numbers[j]
            numbers[j] = numbers[k]
            numbers[k] = temp
            k -= 1
            j -= 1
        i += 1
    return numbers

def inPlaceMergeSort(numbers):
    slayDragons = True
    return

def printSorted(numbers):
    for i in numbers:
        print(i)
    return

def createList():
    numbers = []
    i = 0
    while i < 10:
        someNum = random.randint(1, 10)
        numbers.append(someNum)
        i += 1
    return numbers

def recFib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return recFib(n-1) + recFib(n-2)
    return

def itFib(n):
    start = time.time()
    fib = 0
    a = 1
    t = 0
    k = 1
    while k <= n:
        t = fib + a
        a = fib
        fib = t
        k += 1
    end = time.time()
    timer = end - start
    print("Itr: " + repr(n) + " items in " + repr(timer) + " seconds")
    return

def main():
    #myNumbers = []
    #myNumbers = createList()
    #myNumbers = inPlaceInsertionSort(myNumbers)
    #printSorted(myNumbers)
    t = 25
    while t <= 120001:
        fib = itFib(t)
        #start = time.time()
        #recFib(t)
        #end = time.time()
        #print("Recur: " + repr(t) + " items in " + repr(end - start) + " seconds\n")
        t *= 2


if __name__ == "__main__":
    main()