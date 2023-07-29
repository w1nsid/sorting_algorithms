# Sorting Algorithms

## Bubble Sort
```python
def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(len(arr)-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
```

## Selection Sort
```python
def selection_sort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i+1, len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr
```
#### Question #0

What is the time complexity of accessing the nth element of a doubly linked list?

*   O(n)
    

#### Question #1

What is the time complexity of best case deletion from a hash table with the implementation you used during the previous Hash Table C project (chaining)?

*   O(1)
    

#### Question #2

What is the time complexity of searching for an element - worst case - in a hash table with the implementation you used during the previous Hash Table C project (chaining)?

*   O(n)
    

#### Question #3

What is the time complexity of searching for an element in a stack of size n?

*   O(n)
    

#### Question #4

What is the time complexity of this function / algorithm?

```c
    void f(unsigned int n)
    {
    int i;
    
    for (i = 1; i < n; i = i * 2)
    {
    printf("[%d]\n", i);
    }
    }
```

*   O(log(n))
    

#### Question #5

What is the time complexity of accessing the nth element on an unsorted array?

*   O(1)
    

#### Question #6

What is the time complexity of this function / algorithm?

```c
    int Fibonacci(int number)
    {
    if (number <= 1) return number;
    
    return Fibonacci(number - 2) + Fibonacci(number - 1);
    }
```
    

*   O(2^n)
    

#### Question #7

What is the time complexity of this function / algorithm?

```c
    void f(int n)
    {
    printf("n = %d\n", n);
    }
```

*   O(1)
    

#### Question #8

What is the time complexity of this function / algorithm?

```c
    void f(unsigned int n)
    {
    int i;
    int j;
    
    for (i = 0; i < n; i++)
    {
    for (j = 1; j < n; j = j * 2)
    {
        printf("[%d] [%d]\n", i, j);
    }
    }
    }
```
    

*   O(nlog(n))
    

#### Question #9

What is the time complexity of accessing the nth element of a singly linked list?

*   O(n)
    

#### Question #10

What is the time complexity of inserting into an unsorted Python 3 list at index n?

*   O(n)
    

#### Question #11

What is the time complexity of removing at index n from an unsorted Python 3 list?

*   O(n)
    

#### Question #12

Assuming you have a pointer to the node to set the value of, what is the time complexity of setting the value of the nth element in a doubly linked list?

*   O(1)
    

#### Question #13

What is the time complexity of this function / algorithm?

```c
    var factorial = function(n) {
    if(n == 0) {
    return 1
    } else {
    return n * factorial(n - 1);
    }
    }
```    

*   O(n)
    

#### Question #14

What is the time complexity of searching for an element in a queue of size n if you are given a pointer to both the head and the tail of the queue?

*   O(n)
    

#### Question #15

What is the best case time complexity of insertion in a hash table with the implementation you used during the previous Hash Table C project (chaining)?

*   O(1)
    

#### Question #16

What is the time complexity of searching for an element in an unsorted array of size n?

*   O(n)
    

#### Question #17

What is the time complexity of the “pop” operation onto a stack?

*   O(1)
    

#### Question #18

What is the time complexity of setting value at index n in an unsorted Python 3 list?

*   O(1)
    

#### Question #19

What is the time complexity of worst case deletion from a hash table with the implementation you used during the previous Hash Table C project (chaining)?

*   O(n)
    

#### Question #20

What is the best case time complexity searching for an element in a hash table with the implementation you used during the previous Hash Table C project (chaining)?

*   O(1)
    

#### Question #21

What is the time complexity of searching for an element in an unsorted Python 3 list of size n?

*   O(n)
    

#### Question #22

What is the time complexity of “pushing” an element into a queue if you are given a pointer to both the head and the tail of the queue?

*   O(1)
    

#### Question #23

What is the time complexity of the “push” operation onto a stack?

*   O(1)
    

#### Question #24

What is the time complexity of inserting after the nth element of a singly linked list? (Assuming you have a pointer to the node to insert)

*   O(n)
    

#### Question #25

What is the time complexity of this function / algorithm?

```c
    void f(int n)
    {
    int i;
    int j;
    
    for (i = 0; i < n; i++)
    {
    if (i % 2 == 0)
    {
        for (j = 1; j < n; j = j * 2)
        {
            printf("[%d] [%d]\n", i, j);
        }
    }
    else
    {
        for (j = 0; j < n; j = j + 2)
        {
            printf("[%d] [%d]\n", i, j);
        }
    }
    }
    }
```

*   O(n^2)
    

#### Question #26

What is the time complexity accessing the nth element in an unsorted Python 3 list?

*   O(1)
    

#### Question #27

Assuming you have a pointer to the node to remove, what is the time complexity of removing the nth element of a doubly linked list?

*   O(1)
    

#### Question #28

What is the time complexity of this function / algorithm?

```c
    void f(int n)
    {
    int i;
    int j;
    
    for (i = 0; i < n; i++)
    {
      for (j = i + 1; j < n; j++)
      {
           printf("[%d] [%d]\n", i, j);
      }
    }
    }
```

*   O(n^2)
    

#### Question #29

What is the time complexity of inserting at index n on an unsorted array?

*   O(n)
    

#### Question #30

What is the time complexity of searching for an element in a singly linked list of size n?

*   O(n)
    

#### Question #31

What is the time complexity of this function / algorithm?

```c
    void f(int n)
    {
    int i;
    
    for (i = 0; i < n; i += 98)
    {
    printf("[%d]\n", i);
    }
    }
```

*   O(n)
    

#### Question #32

Assuming you have a pointer to the node to insert, what is the time complexity of inserting after the nth element of a doubly linked list?

*   O(n)
    

#### Question #33

What is the time complexity of this function / algorithm?

```bash
    foreach($numbers as $number)
    {
    echo $number;
    }
```

*   O(n)
    

#### Question #34

What is the time complexity of setting a value at index n in an unsorted array?

*   O(1)
    

#### Question #35

What is the time complexity of setting the value of the nth element in a singly linked list? (Assuming you have a pointer to the node to set the value of)

*   O(1)
    

#### Question #36

What is the time complexity of searching for an element in a doubly linked list of size n?

*   O(n)
    

#### Question #37

What is the time complexity of removing the nth element of a singly linked list? (Assuming you have a pointer to the node to remove)

*   O(n)
    

#### Question #38

What is the time complexity of removing at index n in an unsorted array?

*   O(n)
    

#### Question #39

What is the time complexity of this function / algorithm?

```c
    void f(int n)
    {
    int i;
    
    for (i = 0; i < n; i++)
    {
    printf("[%d]\n", i);
    }
    }
```

*   O(n)
    

#### Question #40

What is the time complexity of “popping” an element in a queue if you are given a pointer to both the head and the tail of the queue?

*   O(1)
    

#### Question #41

What is the worst case time complexity of insertion in a hash table with the implementation you used during the previous Hash Table C project (chaining)?

*   O(1)
    

#### Question #42

What is the time complexity of this function / algorithm?

```c
    def func(n):
    a=5
    b=6
    c=10
    for i in range(n):
    for j in range(n):
        x = i * i
        y = j * j
        z = i * j
    for k in range(n):
    w = a*k + 45
    v = b*b
    d = 33
```

*   O(n^2)