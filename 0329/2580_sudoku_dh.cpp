#include <iostream>

int arr[9][9];

void print_arr()
{
  for (int i=0; i<9; i++)
  {
    for (int j=0; j<9; j++)
    {
      std::cout << arr[i][j];
      if (j != 8)
      {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }
}

bool check(int r, int c)
{
  int ver[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int hor[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int box[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int box_r = r / 3 * 3;
  int box_c = c / 3 * 3;
  for (int i=0; i<9; i++)
  {
    // check vertically
    ver[arr[i][c]] += 1;
    // check horizontally
    hor[arr[r][i]] += 1;
    // check box
    box[arr[box_r + i / 3][box_c + i % 3]] += 1;
  }
  for (int j=1; j<10; j++)
  {
    if (ver[j]>1 || hor[j]>1 || box[j]>1) return false;
  }
  return true;
}

void solve(int idx)
{
  if (idx == 9 * 9)
  {
    print_arr();
    exit(0);

  }
  int r = idx / 9;
  int c = idx % 9;
  // 빈칸이 아니면 다음 idx로
  if (arr[r][c] != 0)
  {
    solve(idx + 1);
    return;
  }
  // 빈칸인 경우 경우의 수 확인
  for (int num=1; num<10; num++)
  {
    int v, h, b;
    arr[r][c] = num;
    bool ok = check(r, c);
    if (ok) solve(idx + 1);
    arr[r][c] = 0;
  }
  return;
}

int main(void)
{
  // get arr
  for (int i=0; i<9; i++)
  {
    for (int j=0; j<9; j++)
    {
      std::cin >> arr[i][j];
    }
  }

  // start recursion
  solve(0);
}