"""
File: profiler.py
Defines a class for profiling the list, the number of comparisons.
A Profiler object tracks the list, the number of comparisons and
exchanges, and the running time. The Profiler can also print a trace
and can create a list of unique or duplicate numbers.
Example use:
from profiler import Profiler
from algorithms import selection
p = Profiler()
p.test(selectionSort, size=15, comp=True, exch=True, trace=True)
"""

import time
import random

class Profiler(object):
    def test(self, function, lyst=None, size=10, unique=True,
             comp=True, exch=True, trace=False):
        """
        :param function: the algorithm being profiled
        :param lyst: the search target if profiling a search
        :param size: the size of the list, 10 by default
        :param unique: if True, list contains unique integers
        :param comp: if True, count comparisons
        :param exch: if True, count exchanges
        :param trace: if True, print the list after each exchange
        Run the function with the given attributes and print its
        profile results.
        """
        self.comp = comp
        self.exch = exch
        self.trace = trace
        if lyst != None:
            self.lyst = lyst
        elif unique:
            self.lyst = list(range(1, size + 1))
            random.shuffle(self.lyst)
        else:
            self.lyst = []
        for count in range(size):
            self.lyst.append(random.randint(1, size))
        self.exchCount = 0
        self.cmpCount = 0
        self.startClock()
        function(self.lyst, self)
        self.stopClock()
        print(self)

    def exchange(self):
        """Counts exchanges if on."""
        if self.exch:
            self.exchCount += 1
        if self.trace:
            print(self.lyst)

    def comparison(self):
        """Counts comparisons if on."""
        if self.comp:
            self.cmpCount += 1

    def stopClock(self):
        """Stops the clock and computes the elapsed time
        in seconds, to the nearest millisecond."""
        self.elapsedTime = round(time.time() - self.start, 3)

    def __str__(self):
        """Returns the results as a string"""
        result = "Problem size"
        result += str(len(self.lyst)) + "\n"
        result += "Elapsed time:"
        result += str(self.elapsedTime) + "\n"
        if self.comp:
            result += "Comparisons:"
            result += str(self.cmpCount) + "\n"
        if self.exch:
            result += "Exchanges:"
            result += str(self.exchCount) + "\n"
        return result
