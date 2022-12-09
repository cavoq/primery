# **Primery**
Primery is used to generate prime numbers in a specified range [x, y].
It also measures the time each algorithm needs to generate the prime numbers.
It`s planned to expand the usage for checking primes as well and perfoming other operations.

![license](https://img.shields.io/badge/license-MIT-brightgreen.svg)
![version](https://img.shields.io/badge/version-1.1-lightgrey.svg)

## **Supported algorithms**

| Algorithm | Complexity |
| :---:   | :---: |
| Trial Division | O(n*sqrt(n)) |
| Sieve of Eratosthenes | O(n*log(log(n))) |
| Sieve of Sundaram | O(n*log(n)) |
| Sieve of Atkin | O(n)) |



## **Time comparisons** ##

**Hardware:**
    
    CPU: 11th Gen Intel© Core™ i7-11800H @ 2.30GHz × 8
    GPU: Intel Corporation TigerLake-H GT1 [UHD Graphics]

**Single threaded:**

<table style="border: 1px solid black; border-collapse: collapse;">
  <tr>
    <th>n</th>
    <th>Sieve of Eratosthenes</th>
    <th>Sieve of Sundaram</th>
    <th>Sieve of Atkin</th>
  </tr>
  <tr>
    <th>10⁵</th>
    <td>0.718 ms</td>
    <td>0.602 ms</td>
    <td>0.936 ms</td>
  </tr>
  </tr>
  <tr>
    <th>10⁶</th>
    <td>7.544 ms</td>
    <td>6.956 ms</td>
    <td>8.386 ms</td>
  </tr>
  <tr>
    <th>10⁷</th>
    <td>66.149 ms</td>
    <td>65.015 ms</td>
    <td>62.988 ms</td>
  </tr>
  <tr>
    <th>10⁸</th>
    <td>0.947 s</td>
    <td>1.007 s</td>
    <td>0.837 s</td>
  </tr>
  <tr>
    <th>10⁹</th>
    <td>10.956 s</td>
    <td>16.559 s</td>
    <td>8.839 s</td>
  </tr>
</table>


**Mulit threaded:**

<table style="border: 1px solid black; border-collapse: collapse;">
  <tr>
    <th>n</th>
    <th>Sieve of Eratosthenes</th>
    <th>Sieve of Sundaram</th>
    <th>Sieve of Atkin</th>
  </tr>
  <tr>
    <th>10⁵</th>
    <td>3.197 ms</td>
    <td>27.105 ms</td>
    <td>10.941 ms</td>
  </tr>
  </tr>
  <tr>
    <th>10⁶</th>
    <td>11.735 ms</td>
    <td>140.159 ms</td>
    <td>40.063 ms</td>
  </tr>
  <tr>
    <th>10⁷</th>
    <td>62.772 ms</td>
    <td>1.195 s</td>
    <td>122.007 ms</td>
  </tr>
  <tr>
    <th>10⁸</th>
    <td>0.49 s</td>
    <td>11.984 s</td>
    <td>0.511 s</td>
  </tr>
  <tr>
    <th>10⁹</th>
    <td>7.284 s</td>
    <td> - </td>
    <td>3.903 s</td>
  </tr>
</table>

**Conclusion:**

Based on the data in the tables, it appears that the Sieve of Atkin is the fastest algorithm for generating prime numbers in both single-threaded and multi-threaded environments. In single-threaded mode, it is faster than the other two algorithms for all values of n tested. In multi-threaded mode, it is still the fastest algorithm for n up to 10⁸, and is competitive with the Sieve of Eratosthenes for n = 10⁹. The Sieve of Sundaram is slower than the other two algorithms in both single-threaded and multi-threaded mode. For large inputs, multithreading gives a great perfomance boost for generating prime numbers.

## **Makefile**

![Screenshot from 2022-12-07 23-44-48](https://user-images.githubusercontent.com/61215846/206315507-531a842c-a1c7-41e0-82f3-41566bfabe05.png)

## **Usage**

![Screenshot from 2022-12-09 16-17-27](https://user-images.githubusercontent.com/61215846/206734128-0327fae5-388d-4348-b831-009d38c875d6.png)

