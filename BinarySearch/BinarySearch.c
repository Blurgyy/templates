/*
    �������鳤�Ⱥ�Ҫ��������������һ�����֣��ҳ�Ҫ���������ֵ�λ�á�
        ���룺5 1
              1 2 3 4 5
        �����1

        ���룺10 99
              1 66 88 99 26 12 45 978 36 24
        �����4

    Note :�������������ݱ�������
*/







#include<stdio.h>
int num[100000];
int binary_search(int begin, int end, int e)
{
    int mid, left = begin, right = end;
    while(left <= right)
    {
        mid=(left + right)>>1;
        //printf("left = %d\nmid = %d\nright = %d\n\n", left, mid, right);
        if(num[mid] == e)return mid;
        else if(num[mid] > e) return binary_search(left, mid - 1, e);
        else return binary_search(mid + 1, right, e);
    }
    return -1;
}
int main()
{
    int lenth, e, i;
    while(scanf("%d%d", &lenth, &e) != EOF)
    {
        for(i = 0; i < lenth; i++)
            scanf("%d",num+i);
        binary_search(0, lenth - 1, e) == -1 ? printf("There's no result.\n\n") : printf("The result is %d.\n\n",binary_search(0, lenth - 1, e) + 1);
        for(i = 0; i < lenth; i++)
            num[i] = -1;
    }
    return 0;
}





