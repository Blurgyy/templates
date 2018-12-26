void sort(int a[], int left, int right)
{
    int i = left, j = right, key = a[i];
    if(i >= j)return; //
    while(i < j)
    {
        while(i < j && a[j] > /**/key) j--;
        a[i] = a[j];
        while(i < j && a[i] < /**/key) i++;
        a[j] = a[i];
    }
    a[i] = key;
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}
