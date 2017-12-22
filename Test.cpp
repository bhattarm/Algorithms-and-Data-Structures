void Swap(int data[], int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

void partition(int a[], int l, int r, int &i, int &j)
{
    i = l-1, j = r;
    int p = l-1, q = r;
    int v = a[r];
 
    while (true)
    {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely terminate
        // as v is last element
        while (a[++i] < v);
 
        // From right, find the first element smaller than or
        // equal to v
        while (v < a[--j])
            if (j == l)
                break;
 
        // If i and j cross, then we are done
        if (i >= j) break;
 
        // Swap, so that smaller goes on left greater goes on right
        Swap(a,i, j);
 
        // Move all same left occurrence of pivot to beginning of
        // array and keep count using p
        if (a[i] == v)
        {
            p++;
            Swap(a,p,i);
        }
 
        // Move all same right occurrence of pivot to end of array
        // and keep count using q
        if (a[j] == v)
        {
            q--;
            Swap(a,j,q);
        }
    }
 
    // Move pivot element to its correct index
    Swap(a,i, r);
 
    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i-1;
    for (int k = l; k < p; k++, j--)
        Swap(a,k,j);
 
    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i+1;
    for (int k = r-1; k > q; k--, i++)
        Swap(a,i,k);
}
 
// 3-way partition based quick sort
void quicksort(int a[], int l, int r)
{
    if (r <= l) return;
 
    int i, j;
 
    // Note that i and j are passed as reference
    partition(a, l, r, i, j);
 
    // Recur
    quicksort(a, l, j);
    quicksort(a, i, r);
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
    quicksort(data,0,24);
    for(int i = 0; i < 25; i++)
    {
        std::cout<<data[i]<<' ';
    }
    std::cout<<'\n';
}