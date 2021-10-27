/*
    Author: Utkarsh
    Institute: IIIT Guwahati
    e-mail: utk.akt@gmail.com
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct Point
{
    int x, y;
} Point;

typedef struct Pair
{
    float d;
    Point p1, p2;
} Pair;

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Pair bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    Point p1, p2;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dist(P[i], P[j]) < min)
            {
                min = dist(P[i], P[j]);
                p1 = P[i];
                p2 = P[j];
            }
        }
    }

    Pair res_pair;
    res_pair.d = min;
    res_pair.p1 = p1;
    res_pair.p2 = p2;

    return res_pair;
}

float min(float x, float y)
{
    return (x < y) ? x : y;
}

Pair min_pair(Pair p1, Pair p2)
{
    return (p1.d < p2.d) ? p1 : p2;
}

//For qsort
/*  compare: A pointer to a function that that compares two elements.
    It returns
        a negative integer if the first argument is less than the second
        a positive integer if the first argument is greater than the second
        zero if both arguments are equal.   */

int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

Pair stripClosest(Point strip[], int len, float d, Pair d_pair)
{
    float min = d;
    qsort(strip, len, sizeof(Point), compareY);

    Point p1 = d_pair.p1, p2 = d_pair.p2;
    Pair res_pair;

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len && (strip[j].y - strip[i].y) < min; j++)
        {
            min = dist(strip[i], strip[j]);
            p1 = strip[i];
            p2 = strip[j];
        }
    }

    res_pair.d = min;
    res_pair.p1 = p1;
    res_pair.p2 = p2;

    return res_pair;
}

Pair closestHelper(Point P[], int n)
{
    if (n <= 3)
    {
        return bruteForce(P, n);
    }

    int mid = n / 2;
    Point midp = P[mid];

    Pair pair_left = closestHelper(P, mid);
    Pair pair_right = closestHelper(P + mid, n - mid);

    Pair d_pair = min_pair(pair_left, pair_right);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(P[i].x - midp.x) < d_pair.d)
        {
            strip[j] = P[i];
            j++;
        }
    }

    return min_pair(d_pair, stripClosest(strip, j, d_pair.d, d_pair));
}

Pair closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    return closestHelper(P, n);
}

int main()
{
    unsigned int n;

    cout << "Enter number of Points: " << endl;
    cin >> n;

    Point P[n]; // eg for n = 6: {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    cout << "Enter the Points <x-coordinate> <y-coordinate>:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> P[i].x >> P[i].y;
    }

    cout << "The closest Pair of Points are: " << endl;
    cout << "Point 1:\t\tPoint 2:" << endl;

    Pair result = closest(P, n);

    cout << "(" << result.p1.x << ", " << result.p1.y << ")\t\t"
         << "(" << result.p2.x << ", " << result.p2.y << ")" << endl;
    cout << "And the distance between them is: " << result.d << endl;

    return 0;
}