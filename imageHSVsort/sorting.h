#ifndef SORTING
#define SORTING

template<class T>
void merge(std::vector<T>& v, int p, int q, int r)
{
    int size1 = q - p + 1;
    int size2 = r - q;
    std::vector<T> L(size1);
    std::vector<T> R(size2);

    for (int i = 0; i < size1; i++)
    {
        L[i] = v[p + i];
    }
    for (int j = 0; j < size2; j++)
    {
        R[j] = v[q + j + 1];
    }

    int i = 0, j = 0;
    int k;
    for (k = p; k <= r && i < size1 && j < size2; k++)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }
    for (i = i; i < size1; ++i)
    {
        v[k] = L[i];
        k++;
    }

    for (j = j; j < size2; j++)
    {
        v[k] = R[j];
        k++;
    }
}

template<class T>
void merge_sort(std::vector<T>& v, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}


#endif
