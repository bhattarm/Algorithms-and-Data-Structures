
/*
By: Madan Bhattarai
Sorting Algorithms
*/

/***************************************InsertationSort******************************************/

template<class T>
void InsertationSort(T data[], int n)
{
    int i, j;
    T temp;

    for(i = 1; i < n; i++)
    {
        temp = data[i];
        j = i;

        
        while(j > 0 && temp < data[j-1])
        {
            data[j] = data[j-1];
            j--;
        }
        data[j] = temp;
    }
}

template<class T>
void InsertationSort(T data[], int n, bool (*comperator)(T,T))
{
    int i, j;
    T temp;

    for(i = 1; i < n; i++)
    {
        temp = data[i];
        j = i;

        while(j > 0 && comperator(temp, data[j-1]) == true)
        {
            data[j] = data[j-1];
            j--;
        }
        data[j] = temp;
    }
}

/********************************************SelectionSort******************************************/

template<class T>
void Swap(T data[], int i, int j)
{
    T temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

template<class T>
void SelectionSort(T data[], int n)
{
    int i,j,least;

    for(i = 0; i < n-1; i++)
    {
        for(j = i+1, least = i; j < n; j++)
        {
            if(data[j] < data[least])
                least = j;
        }
        if(i != least)
            Swap(data,least,i);
    }
}

template<class T>
void SelectionSort(T data[], int n, bool (*comperator)(T,T))
{
    int i,j,least;

    for(i = 0; i < n-1; i++)
    {
        for(j = i+1, least = i; j < n; j++)
        {
            if(comperator(data[j],data[least]) == true)
                least = j;
        }
        if(i != least)
            Swap(data,least,i);
    }
}

/************************************Bubble Sort************************************************/

/*
Bubble sort with flag if the array is sorted
*/

template<class T>
void BubbleSort(T data[], int n)
{
    int i, j, another_loop;

    for(i = 0, another_loop = 1; i < n-1 && another_loop; i++)
    {
        for(j = n-1, another_loop = 0; j > i; --j)
        {
            if(data[j] < data[j-1])
            {
                Swap(data,j,j-1);
                another_loop = 1;
            }
        }
    }
}

template<class T>
void BubbleSort(T data[], int n, bool (*comperator)(T,T))
{
    int i, j, another_loop;

    for(i = 0, another_loop = 1; i < n-1 && another_loop; i++)
    {
        for(j = n-1, another_loop = 0; j > i; --j)
        {
            if(comperator(data[j],data[j-1]) == true)
            {
                Swap(data,j,j-1);
                another_loop = 1;
            }
        }
    }
}

/************************************Heap Sort*************************************************/

template<class T>
void Heapify(T data[], int first, int last)
{
    int largest = 2*first + 1;
  
    while(largest <= last)
    {
        if(largest < last)
            if(data[largest] < data[largest+1])
                largest++;
        
        //Swap the values if necessary
        if(data[first] < data[largest])
        {
            Swap(data,first,largest);
            first = largest;
            largest = 2*first + 1;
        }
        else
            largest = last+1;
    } 
}


template<class T>
void Heapify(T data[], int first, int last, bool (*comperator)(T,T))
{
    int largest = 2*first + 1;

    while(comperator(largest,last) == true)
    {
        if(comperator(largest,last) == true)
            if(comperator(data[largest],data[largest+1]) == true)
                largest++;
        
        //Swap the values if necessary
        if(comperator(data[first],data[largest]) == true)
        {
            Swap(data,first,largest);
            first = largest;
            largest = 2*first + 1;
        }
        else
            largest = last+1;
    }
}

template<class T>
void HeapSort(T data[], int array_size)
{
    int i;

    //Create a heap
    for(i = (array_size/2) - 1; i >= 0; --i)
    {
        Heapify(data,i,array_size-1);
    }

    for(i = array_size - 1; i > 1; --i)
    {
        Swap(data,0,i);
        Heapify(data,0,i-1);
    }

   
    if(data[0] > data[1])
    {
        Swap(data,0,1);
    }
}

template<class T>
void HeapSort(T data[], int array_size, bool (*comperator)(T,T))
{
    int i;

    //Create a heap
    for(i = (array_size/2) - 1; i >= 0; --i)
    {
        Heapify(data,i,array_size-1,comperator);
    }

    for(i = array_size - 1; i > 1; --i)
    {
        Swap(data,0,i);
        Heapify(data,0,i-1,comperator);
    }


    if(comperator(data[0],data[1]) == false)
        Swap(data,0,1);
    
}

/****************************************Quick Sort*********************************************/

template<class T>
void QuickSort(T data[], int first, int last)
{
  
    int lower = first, upper = last;
    T bound = data[(first+last)/2];

    //Partation
    while(lower <= upper)
    {
        while(data[lower] < bound)
            lower++;
        while(bound < data[upper])
            upper--;
        if(lower < upper)
            Swap(data,lower++,upper--);
        else
            lower++;
    }

    //Call teh QuickSort recursively
    if(first < upper)
        QuickSort(data,first,upper);
    if((upper+1) < last)
        QuickSort(data,upper+1,last);
}

template<class T>
void QuickSort(T data[], int first, int last, bool (*comperator)(T,T))
{
    int lower = first, upper = last;
    T bound = data[(first+last)/2];

    //Partation
    while(lower <= upper)
    {
        while(comperator(data[lower],bound) == true)
            lower++;
        while(comperator(bound,data[upper]) == true)
            upper--;
        if(lower < upper)
            Swap(data,lower++,upper--);
        else
            lower++;
    }

    //Call the QuickSort recursively
    if(first < upper)
        QuickSort(data,first,upper,comperator);
    if((upper+1) < last)
        QuickSort(data,upper+1,last,comperator);
}

/****************************************QSort*************************************************/
//Optimized version of QuickSort

template<class T>
void QSort(T data[], int first, int last)
{

    int lower = first+1, upper = last;
    T bound;

    Swap(data,first,(first+last)/2);
    bound = data[first];

    //Partition
    while(lower <= upper)
    {
        while(data[lower] < bound)
            lower++;
        while(bound < data[upper])
            upper--;
        if(lower < upper)
            Swap(data,lower++,upper--);
        else
            lower++;
    }

    //Call the QuickSort recursively
    if(first < (upper-1))
        QSort(data,first,upper-1);
    if((upper+1) < last)
        QSort(data,upper+1,last);
}

template<class T>
void QSort(T data[], int first, int last, bool (*comperator)(T,T))
{
    int lower = first+1, upper = last;
    T bound;

    Swap(data,first,(first+last)/2);
    bound = data[first];

    //Partition
    while(lower <= upper)
    {
        while(comperator(data[lower],bound) == true)
            lower++;
        while(comperator(bound,data[upper]) == true)
            upper--;
        if(lower < upper)
            Swap(data,lower++,upper--);
        else
            lower++;
    }

    //Call the QuickSort recursively
    if(first < (upper-1))
        QSort(data,first,upper-1,comperator);
    if((upper+1) < last)
        QSort(data,upper+1,last,comperator);
}



bool int_compare(int i, int j)
{
    return i < j;
}

#include <iostream>
int main()
{
    //int data[] = {5,5,5,3,2,10,8,1,1,1,11,15,16,16,16,16};
    int data[] = {3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,2,1,1,1,1};

    for(int i = 0; i < 25; i++)
    {
        std::cout<<data[i]<<' ';
    }
    std::cout<<'\n';
    InsertationSort<int>(data,25,int_compare);
    for(int i = 0; i < 25; i++)
    {
        std::cout<<data[i]<<' ';
    }
    std::cout<<'\n';
}