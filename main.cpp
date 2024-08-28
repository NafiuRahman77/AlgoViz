#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <bits/stdc++.h>
#include <time.h>
using namespace sf;
using namespace std;

void SelectionSort(RenderWindow &window, RectangleShape rects[], int heights[], int n, Font &myFont)
{
      for (int i = 0; i < n - 1; i++)
      {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                  if (heights[j] < heights[minIndex])
                  {
                        minIndex = j;
                  }
            }
            if (minIndex != i)
            {
                  swap(heights[i], heights[minIndex]);

                  window.clear();
                  for (int k = 0; k < n; k++)
                  {
                        if (k == i)
                        {
                              rects[k].setFillColor(Color::Green);
                        }
                        else if (k == minIndex)
                        {
                              rects[k].setFillColor(Color::Red); // Highlight the swapped elements
                        }
                        else
                        {
                              rects[k].setFillColor(Color::White);
                        }
                        rects[k].setSize(Vector2f(10, heights[k]));
                        rects[k].setPosition(k * 12, 900 - heights[k]);
                        window.draw(rects[k]);
                  }
                  window.display();
                  sleep(milliseconds(50)); // Delay for visualization
            }
      }
}

void BubbleSort(RenderWindow &window, RectangleShape rects[], int heights[], int n, Font &myFont)
{
      for (int i = 0; i < n - 1; i++)
      {
            for (int j = 0; j < n - i - 1; j++)
            {
                  if (heights[j] > heights[j + 1])
                  {
                        swap(heights[j], heights[j + 1]);

                        window.clear();
                        for (int k = 0; k < n; k++)
                        {
                              if (k == j)
                              {
                                    rects[k].setFillColor(Color::Red);
                              }
                              else if (k == j + 1)
                              {
                                    rects[k].setFillColor(Color::Green);
                              }
                              else
                              {
                                    rects[k].setFillColor(Color::White);
                              }
                              rects[k].setSize(Vector2f(10, heights[k]));
                              rects[k].setPosition(k * 12, 900 - heights[k]);
                              window.draw(rects[k]);
                        }
                        window.display();
                        sleep(milliseconds(50)); // Delay for visualization
                  }
            }
      }
}

// insertion sort
void InsertionSort(RenderWindow &window, RectangleShape rects[], int heights[], int n, Font &myFont)
{
      for (int i = 1; i < n; i++)
      {
            int key = heights[i];
            int j = i - 1;

            while (j >= 0 && heights[j] > key)
            {
                  heights[j + 1] = heights[j];
                  j = j - 1;
            }
            heights[j + 1] = key;

            window.clear();
            for (int k = 0; k < n; k++)
            {
                  if (k == j)
                  {
                        rects[k].setFillColor(Color::Red);
                  }

                  else if (k == i)
                  {
                        rects[k].setFillColor(Color::Green);
                  }
                  else
                  {
                        rects[k].setFillColor(Color::White);
                  }
                  rects[k].setSize(Vector2f(10, heights[k]));
                  rects[k].setPosition(k * 12, 900 - heights[k]);
                  window.draw(rects[k]);
            }
            window.display();
            sleep(milliseconds(50)); // Delay for visualization
      }
}

// merge sort
void merge(int arr[], int l, int m, int r, RenderWindow &window, RectangleShape rects[], int n)
{
      int i, j, k;
      int n1 = m - l + 1;
      int n2 = r - m;

      int L[n1], R[n2];

      for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
      for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

      i = 0;
      j = 0;
      k = l;
      while (i < n1 && j < n2)
      {
            if (L[i] <= R[j])
            {
                  arr[k] = L[i];
                  window.clear();
                  for (int p = 0; p < n; p++)
                  {
                        if (p == k)
                        {
                              rects[k].setFillColor(Color::Green);
                        }
                        else if (arr[p] == L[i])
                        {
                              rects[k].setFillColor(Color::Red);
                        }

                        else
                        {
                              rects[p].setFillColor(Color::White);
                        }
                        rects[p].setSize(Vector2f(10, arr[p]));
                        rects[p].setPosition(p * 12, 900 - arr[p]);
                        window.draw(rects[p]);
                  }
                  window.display();

                  i++;
            }
            else
            {
                  arr[k] = R[j];
                  window.clear();
                  for (int p = 0; p < n; p++)
                  {
                        if (p == k)
                        {
                              rects[k].setFillColor(Color::Green);
                        }
                        else if (arr[p] == R[j])
                        {
                              rects[k].setFillColor(Color::Red);
                        }

                        else
                        {
                              rects[p].setFillColor(Color::White);
                        }
                        rects[p].setSize(Vector2f(10, arr[p]));
                        rects[p].setPosition(p * 12, 900 - arr[p]);
                        window.draw(rects[p]);
                  }
                  window.display();
                  j++;
            }
            k++;
      }

      while (i < n1)
      {
            arr[k] = L[i];
            window.clear();
            for (int p = 0; p < n; p++)
            {
                  if (p == k)
                  {
                        rects[k].setFillColor(Color::Green);
                  }
                  else if (arr[p] == L[i])
                  {
                        rects[k].setFillColor(Color::Red);
                  }

                  else
                  {
                        rects[p].setFillColor(Color::White);
                  }
                  rects[p].setSize(Vector2f(10, arr[p]));
                  rects[p].setPosition(p * 12, 900 - arr[p]);
                  window.draw(rects[p]);
            }
            window.display();
            i++;
            k++;
      }

      while (j < n2)
      {
            arr[k] = R[j];
            window.clear();
            for (int p = 0; p < n; p++)
            {
                  if (p == k)
                  {
                        rects[k].setFillColor(Color::Green);
                  }
                  else if (arr[p] == R[j])
                  {
                        rects[k].setFillColor(Color::Red);
                  }

                  else
                  {
                        rects[p].setFillColor(Color::White);
                  }
                  rects[p].setSize(Vector2f(10, arr[p]));
                  rects[p].setPosition(p * 12, 900 - arr[p]);
                  window.draw(rects[p]);
            }
            window.display();
            j++;
            k++;
      }

      sleep(milliseconds(50)); // Delay for visualization
}

void mergeSort(int arr[], int l, int r, RenderWindow &window, RectangleShape rects[], int n)
{
      if (l >= r)
            return;
      int m = l + (r - l) / 2;
      mergeSort(arr, l, m, window, rects, n);
      mergeSort(arr, m + 1, r, window, rects, n);
      merge(arr, l, m, r, window, rects, n);
}

// quick sort
int partition(int arr[], int low, int high, RenderWindow &window, RectangleShape rects[], int n)
{
      int pivot = arr[high];
      int i = (low - 1);

      for (int j = low; j <= high - 1; j++)
      {
            if (arr[j] < pivot)
            {
                  i++;
                  swap(arr[i], arr[j]);
                  window.clear();
                  for (int p = 0; p < n; p++)
                  {
                        if (p == i)
                        {
                              rects[i].setFillColor(Color::Green);
                        }
                        else if (arr[p] == arr[i])
                        {
                              rects[i].setFillColor(Color::Red);
                        }

                        else
                        {
                              rects[p].setFillColor(Color::White);
                        }
                        rects[p].setSize(Vector2f(10, arr[p]));
                        rects[p].setPosition(p * 12, 900 - arr[p]);
                        window.draw(rects[p]);
                  }
                  window.display();
            }
      }
      swap(arr[i + 1], arr[high]);
      return (i + 1);
}

void quickSort(int arr[], int low, int high, RenderWindow &window, RectangleShape rects[], int n)
{
      if (low < high)
      {
            int pi = partition(arr, low, high, window, rects, n);
            quickSort(arr, low, pi - 1, window, rects, n);
            quickSort(arr, pi + 1, high, window, rects, n);
      }
}

// binary search
int binarySearch(int arr[], int l, int r, int x, RenderWindow &window, RectangleShape rects[], int n)
{
      while (l <= r)
      {
            int m = l + (r - l) / 2;

            if (arr[m] == x)
            {
                  window.clear();
                  for (int i = 0; i < n; i++)
                  {
                        if (i == m)
                        {
                              rects[i].setFillColor(Color::Green);
                        }
                        else
                        {
                              rects[i].setFillColor(Color::White);
                        }
                        rects[i].setSize(Vector2f(10, arr[i]));
                        rects[i].setPosition(i * 12, 900 - arr[i]);
                        window.draw(rects[i]);
                  }
                  window.display();
                  return m;
            }

            if (arr[m] < x)
            {
                  l = m + 1;
            }
            else
            {
                  r = m - 1;
            }
            window.clear();
            for (int i = 0; i < n; i++)
            {
                  if (i == m)
                  {
                        rects[i].setFillColor(Color::Red);
                  }
                  else if (i == l || i == r)
                  {
                        rects[i].setFillColor(Color::Yellow);
                  }

                  else
                  {
                        rects[i].setFillColor(Color::White);
                  }
                  rects[i].setSize(Vector2f(10, arr[i]));
                  rects[i].setPosition(i * 12, 900 - arr[i]);
                  window.draw(rects[i]);
            }
            window.display();
            sleep(milliseconds(500)); // Delay for visualization
      }

      return -1;
}

int maxSearch(int arr[], RenderWindow &window, RectangleShape rects[], int n)
{
      int max_no = INT_MIN;
      for (int i = 0; i < n; i++)
      {
            max_no = std::max(max_no, arr[i]);

            window.clear();
            for (int k = 0; k < n; k++)
            {
                  if (arr[k] == max_no && k <= i)
                  {
                        rects[k].setFillColor(Color::Red);
                  }
                  else if (k == i)
                  {
                        rects[k].setFillColor(Color::Yellow);
                  }

                  else
                  {
                        rects[k].setFillColor(Color::White);
                  }
                  rects[k].setSize(Vector2f(10, arr[k]));
                  rects[k].setPosition(k * 12, 900 - arr[k]);
                  window.draw(rects[k]);
            }
            window.display();
            sleep(milliseconds(50)); // Delay for visualization
      }

      return max_no;
}

int minSearch(int arr[], RenderWindow &window, RectangleShape rects[], int n)
{
      int min_no = INT_MAX;
      for (int i = 0; i < n; i++)
      {
            min_no = std::min(min_no, arr[i]);

            window.clear();
            for (int k = 0; k < n; k++)
            {
                  if (arr[k] == min_no && k <= i)
                  {
                        rects[k].setFillColor(Color::Red);
                  }
                  else if (k == i)
                  {
                        rects[k].setFillColor(Color::Yellow);
                  }

                  else
                  {
                        rects[k].setFillColor(Color::White);
                  }
                  rects[k].setSize(Vector2f(10, arr[k]));
                  rects[k].setPosition(k * 12, 900 - arr[k]);
                  window.draw(rects[k]);
            }
            window.display();
            sleep(milliseconds(50)); // Delay for visualization
      }

      return min_no;
}

// heap sort iterative
void heapify(int arr[], int n, int i, RenderWindow &window, RectangleShape rects[])
{
      int largest = i;
      int l = 2 * i + 1;
      int r = 2 * i + 2;

      if (l < n && arr[l] > arr[largest])
            largest = l;

      if (r < n && arr[r] > arr[largest])
            largest = r;

      if (largest != i)
      {
            swap(arr[i], arr[largest]);
            window.clear();
            for (int j = 0; j < n; j++)
            {
                  if (j == i)
                  {
                        rects[j].setFillColor(Color::Green);
                  }
                  else if (j == largest)
                  {
                        rects[j].setFillColor(Color::Red);
                  }
                  else
                  {
                        rects[j].setFillColor(Color::White);
                  }
                  rects[j].setSize(Vector2f(10, arr[j]));
                  rects[j].setPosition(j * 12, 900 - arr[j]);
                  window.draw(rects[j]);
            }
            window.display();
            heapify(arr, n, largest, window, rects);
      }
}

void heapSort(int arr[], int n, RenderWindow &window, RectangleShape rects[])
{
      for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i, window, rects);

      for (int i = n - 1; i > 0; i--)
      {
            swap(arr[0], arr[i]);
            window.clear();
            for (int j = 0; j < n; j++)
            {
                  if (j == i)
                  {
                        rects[j].setFillColor(Color::Green);
                  }
                  else if (j == 0)
                  {
                        rects[j].setFillColor(Color::Red);
                  }
                  else
                  {
                        rects[j].setFillColor(Color::White);
                  }
                  rects[j].setSize(Vector2f(10, arr[j]));
                  rects[j].setPosition(j * 12, 900 - arr[j]);
                  window.draw(rects[j]);
            }
            window.display();
            heapify(arr, i, 0, window, rects);
      }
}

// radix sort
void radixSort(int arr[], int n, RenderWindow &window, RectangleShape rects[])
{
      int m = *max_element(arr, arr + n);

      for (int exp = 1; m / exp > 0; exp *= 10)
      {
            int output[n];
            int count[10] = {0};

            for (int i = 0; i < n; i++)
            {
                  count[(arr[i] / exp) % 10]++;
            }

            for (int i = 1; i < 10; i++)
            {
                  count[i] += count[i - 1];
            }

            for (int i = n - 1; i >= 0; i--)
            {
                  output[count[(arr[i] / exp) % 10] - 1] = arr[i];
                  count[(arr[i] / exp) % 10]--;
            }

            for (int i = 0; i < n; i++)
            {
                  arr[i] = output[i];
                  window.clear();
                  for (int j = 0; j < n; j++)
                  {
                        if (j == i)
                        {
                              rects[j].setFillColor(Color::Green);
                        }
                        else
                        {
                              rects[j].setFillColor(Color::White);
                        }
                        rects[j].setSize(Vector2f(10, arr[j]));
                        rects[j].setPosition(j * 12, 900 - arr[j]);
                        window.draw(rects[j]);
                  }
                  window.display();
            }
      }
}

void visualizePrimes(RenderWindow &window, Font &myFont, bool isPrime[], int n)
{
      window.clear();
      int cols = 10;
      int rows = 10;
      int number = 1;
      for (int i = 0; i < rows; i++)
      {
            for (int j = 0; j < cols; j++)
            {
                  Text text;
                  text.setFont(myFont);
                  text.setString(to_string(number));
                  text.setCharacterSize(30);
                  text.setFillColor(isPrime[number] ? Color::White : Color::Red);
                  text.setPosition(j * 100 + 20, i * 100 + 20);
                  window.draw(text);
                  number++;
            }
      }
      window.display();
      sleep(milliseconds(50));
}

void sieveOfEratosthenes(RenderWindow &window, Font &myFont, int n)
{
      bool isPrime[n + 1];
      memset(isPrime, true, sizeof(isPrime));
      isPrime[0] = isPrime[1] = false;

      for (int p = 2; p * p <= n; p++)
      {
            if (isPrime[p])
            {
                  for (int i = p * p; i <= n; i += p)
                  {
                        isPrime[i] = false;

                        visualizePrimes(window, myFont, isPrime, n);
                  }
            }
      }

      visualizePrimes(window, myFont, isPrime, n);
}

// reshuffle heights
void reshuffle(int heights[], RectangleShape rects[], int n)
{
      for (int i = 0; i < n; i++)
      {
            heights[i] = rand() % 800 + 100;
      }
      for (int i = 0; i < n; i++)
      {
            rects[i].setSize(Vector2f(10, heights[i]));
            rects[i].setPosition(i * 12, 900 - heights[i]);
            rects[i].setFillColor(Color::White);
      }
}

int main()
{
      srand(time(0));
      RenderWindow window(VideoMode(1600, 900), "Algo Visualiser!");
      window.setFramerateLimit(150);

      int n = 130;
      int arax[n + 1] = {}, aray[n + 1] = {};

      for (int i = 1; i <= n; i++)
      {
            arax[i] = 50 + i * 10;
            aray[i] = rand() % 900 + 1;
      }

      int heights[n];

      for (int i = 0; i < n; i++)
      {
            heights[i] = rand() % 800 + 100;
      }

      RectangleShape rects[n];
      for (int i = 0; i < n; i++)
      {
            rects[i].setSize(Vector2f(10, heights[i]));
            rects[i].setPosition(i * 12, 900 - heights[i]);
            rects[i].setFillColor(Color::White);
      }

      Font myFont;
      if (!myFont.loadFromFile("Font/gomarice_no_continue.ttf"))
      {
            return -1; // error loading font
      }

      int men = 0;
      while (window.isOpen())
      {
            Event event;
            while (window.pollEvent(event))
            {
                  if (event.type == Event::Closed)
                        window.close();
            }

            if (men == 0)
            {
                  double mx = Mouse::getPosition(window).x;
                  double my = Mouse::getPosition(window).y;

                  Text Sort, Find, Prime, End;
                  Sort.setFont(myFont);
                  Sort.setString("Sort");
                  Sort.setFillColor((mx >= 700 && mx <= 800) && (my >= 250 && my < 300) ? Color::Yellow : Color::White);
                  Sort.setStyle(Text::Regular);
                  Sort.setCharacterSize(40);
                  Sort.setPosition(700, 250);

                  Find.setFont(myFont);
                  Find.setString("Find");
                  Find.setFillColor((mx >= 700 && mx <= 800) && (my >= 350 && my < 400) ? Color::Yellow : Color::White);
                  Find.setStyle(Text::Regular);
                  Find.setCharacterSize(40);
                  Find.setPosition(700, 350);

                  Prime.setFont(myFont);
                  Prime.setString("Prime");
                  Prime.setFillColor((mx >= 700 && mx <= 800) && (my >= 450 && my < 500) ? Color::Yellow : Color::White);
                  Prime.setStyle(Text::Regular);
                  Prime.setCharacterSize(40);
                  Prime.setPosition(700, 450);

                  End.setFont(myFont);
                  End.setString("End");
                  End.setFillColor((mx >= 700 && mx <= 800) && (my >= 550 && my < 600) ? Color::Yellow : Color::White);
                  End.setStyle(Text::Regular);
                  End.setCharacterSize(40);
                  End.setPosition(700, 550);

                  if ((mx >= 700 && mx <= 900) && (my >= 250 && my < 300) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        men = 1;
                  }
                  else if ((mx >= 700 && mx <= 900) && (my >= 350 && my < 400) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        men = 2;
                  }
                  else if ((mx >= 700 && mx <= 900) && (my >= 450 && my < 500) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        men = 3;
                  }
                  else if ((mx >= 700 && mx <= 900) && (my >= 550 && my < 600) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        return 0;
                  }

                  window.clear();
                  window.draw(Sort);
                  window.draw(Find);
                  window.draw(Prime);
                  window.draw(End);
                  window.display();
            }
            else if (men == 1)
            {
                  double mx = Mouse::getPosition(window).x;
                  double my = Mouse::getPosition(window).y;

                  Text Sort, BSort, ISort, SSort, QSort, MSort, RdxSort, HSort, Gback;

                  BSort.setFont(myFont);
                  BSort.setString("Bubble Sort");
                  BSort.setFillColor((mx >= 700 && mx <= 950) && (my >= 300 && my <= 350) ? Color::Yellow : Color::White);
                  BSort.setStyle(Text::Regular);
                  BSort.setCharacterSize(40);
                  BSort.setPosition(700, 300);

                  ISort.setFont(myFont);
                  ISort.setString("Intersection Sort");
                  ISort.setFillColor((mx >= 700 && mx <= 1050) && (my >= 400 && my <= 450) ? Color::Yellow : Color::White);
                  ISort.setStyle(Text::Regular);
                  ISort.setCharacterSize(40);
                  ISort.setPosition(700, 400);

                  SSort.setFont(myFont);
                  SSort.setString("Selection Sort");
                  SSort.setFillColor((mx >= 700 && mx <= 950) && (my >= 500 && my <= 550) ? Color::Yellow : Color::White);
                  SSort.setStyle(Text::Regular);
                  SSort.setCharacterSize(40);
                  SSort.setPosition(700, 500);

                  QSort.setFont(myFont);
                  QSort.setString("Quick Sort");
                  QSort.setFillColor((mx >= 700 && mx <= 950) && (my >= 600 && my <= 650) ? Color::Yellow : Color::White);
                  QSort.setStyle(Text::Regular);
                  QSort.setCharacterSize(40);
                  QSort.setPosition(700, 600);

                  MSort.setFont(myFont);
                  MSort.setString("Merge Sort");
                  MSort.setFillColor((mx >= 700 && mx <= 950) && (my >= 700 && my <= 750) ? Color::Yellow : Color::White);
                  MSort.setStyle(Text::Regular);
                  MSort.setCharacterSize(40);
                  MSort.setPosition(700, 700);

                  RdxSort.setFont(myFont);
                  RdxSort.setString("Radix Sort");
                  RdxSort.setFillColor((mx >= 700 && mx <= 950) && (my >= 200 && my <= 250) ? Color::Yellow : Color::White);
                  RdxSort.setStyle(Text::Regular);
                  RdxSort.setCharacterSize(40);
                  RdxSort.setPosition(700, 200);

                  HSort.setFont(myFont);
                  HSort.setString("Heap Sort");
                  HSort.setFillColor((mx >= 700 && mx <= 950) && (my >= 100 && my <= 150) ? Color::Yellow : Color::White);
                  HSort.setStyle(Text::Regular);
                  HSort.setCharacterSize(40);
                  HSort.setPosition(700, 100);

                  Gback.setFont(myFont);
                  Gback.setString("Go back");
                  Gback.setFillColor((mx >= 700 && mx <= 800) && (my >= 850 && my <= 870) ? Color::Yellow : Color::White);
                  Gback.setStyle(Text::Regular);
                  Gback.setCharacterSize(20);
                  Gback.setPosition(700, 850);

                  if ((mx >= 700 && mx <= 1000) && (my >= 200 && my < 250) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        reshuffle(heights, rects, n);
                        radixSort(heights, n, window, rects);
                  }
                  else if ((mx >= 700 && mx <= 1000) && (my >= 100 && my < 150) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        reshuffle(heights, rects, n);
                        heapSort(heights, n, window, rects);
                  }

                  else if ((mx >= 700 && mx <= 950) && (my >= 300 && my <= 350) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        reshuffle(heights, rects, n);
                        BubbleSort(window, rects, heights, n, myFont);
                  }
                  else if ((mx >= 700 && mx <= 950) && (my >= 500 && my <= 550) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        reshuffle(heights, rects, n);
                        SelectionSort(window, rects, heights, n, myFont);
                  }
                  else if ((mx >= 700 && mx <= 1050) && (my >= 400 && my <= 450) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        reshuffle(heights, rects, n);
                        InsertionSort(window, rects, heights, n, myFont);
                  }
                  else if ((mx >= 700 && mx <= 950) && (my >= 700 && my <= 750) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        reshuffle(heights, rects, n);
                        mergeSort(heights, 0, n - 1, window, rects, n);
                  }
                  else if ((mx >= 700 && mx <= 950) && (my >= 600 && my <= 650) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        reshuffle(heights, rects, n);
                        quickSort(heights, 0, n - 1, window, rects, n);
                  }

                  else if ((mx >= 700 && mx <= 800) && (my >= 850 && my <= 870) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        men = 0;
                  }

                  window.clear();
                  window.draw(HSort);
                  window.draw(RdxSort);
                  window.draw(BSort);
                  window.draw(ISort);
                  window.draw(SSort);
                  window.draw(QSort);
                  window.draw(MSort);
                  window.draw(Gback);
                  window.display();
            }
            else if (men == 2)
            {
                  double mx = Mouse::getPosition(window).x;
                  double my = Mouse::getPosition(window).y;

                  Text MaxSearch, MinSearch, BSearch, Gback;

                  BSearch.setFont(myFont);
                  BSearch.setString("Binary Search");
                  BSearch.setFillColor((mx >= 700 && mx <= 1000) && (my >= 500 && my <= 550) ? Color::Yellow : Color::White);
                  BSearch.setStyle(Text::Regular);
                  BSearch.setCharacterSize(40);
                  BSearch.setPosition(700, 500);

                  MinSearch.setFont(myFont);
                  MinSearch.setString("Minimum Search");
                  MinSearch.setFillColor((mx >= 700 && mx <= 1000) && (my >= 300 && my <= 350) ? Color::Yellow : Color::White);
                  MinSearch.setStyle(Text::Regular);
                  MinSearch.setCharacterSize(40);
                  MinSearch.setPosition(700, 300);

                  MaxSearch.setFont(myFont);
                  MaxSearch.setString("Maximum Search");
                  MaxSearch.setFillColor((mx >= 700 && mx <= 1000) && (my >= 400 && my <= 450) ? Color::Yellow : Color::White);
                  MaxSearch.setStyle(Text::Regular);
                  MaxSearch.setCharacterSize(40);
                  MaxSearch.setPosition(700, 400);

                  Gback.setFont(myFont);
                  Gback.setString("Go back");
                  Gback.setFillColor((mx >= 700 && mx <= 800) && (my >= 850 && my <= 870) ? Color::Yellow : Color::White);
                  Gback.setStyle(Text::Regular);
                  Gback.setCharacterSize(20);
                  Gback.setPosition(700, 850);

                  if ((mx >= 700 && mx <= 1000) && (my >= 500 && my <= 550) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        reshuffle(heights, rects, n);
                        int x = rand() % 900 + 1;
                        binarySearch(heights, 0, n - 1, x, window, rects, n);
                  }
                  else if ((mx >= 700 && mx <= 1000) && (my >= 400 && my <= 450) && (Mouse::isButtonPressed(Mouse::Left)))
                  {

                        reshuffle(heights, rects, n);
                        maxSearch(heights, window, rects, n);
                  }

                  else if ((mx >= 700 && mx <= 1000) && (my >= 300 && my <= 350) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        reshuffle(heights, rects, n);
                        minSearch(heights, window, rects, n);
                  }

                  else if ((mx >= 700 && mx <= 800) && (my >= 850 && my <= 870) && (Mouse::isButtonPressed(Mouse::Left)))
                  {
                        men = 0;
                  }

                  window.clear();
                  window.draw(MaxSearch);
                  window.draw(MinSearch);
                  window.draw(BSearch);
                  window.draw(Gback);
                  window.display();
            }
            else if (men == 3)
            {
                  sieveOfEratosthenes(window, myFont, 100);
                  men = 0;
            }
      }

      return 0;
}
