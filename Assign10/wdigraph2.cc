#include "/home/cs340/progs/17f/p10/wdigraph.h"

void wdigraph::depth_first(int u) const
{
  int first = -1;
  bool* visit = NULL;

  if(first == -1)
  {
    first = u;
    visit = new bool(size);
    for(int i = 0; i < size; i++)
      visit[i] = false;
  }

  cout << label[u];
  visit[u] = true;

  for(int j = 0; j != size; j++)
  {
    if(adj_matrix[u][j] != 0 && visit[j] != true)
    {
      cout << "->";
      cout << label[j];
    }
  }
  if(u == first)
  {
    cout << endl << endl;
    first = -1;
    delete[] visit;
    visit = NULL;
  }
}

void wdigraph::print_graph() const
{
  int labelSize = (int) label.size();
  cout << "No. of Nodes= " << size << endl << endl;
  cout << "Adjancy Matrix: " << endl << endl;

  cout << "  |";
  for(int i = 0; i < labelSize; i++)
    cout << "  " << label[i];

  cout << endl << "--|";
  for(int i = 0; i < labelSize; i++)
    cout << "---";
  cout << endl;

  for(int i = 0; i < labelSize; i++)
  {
    cout << label[i] << " |";
    for(int j = 0; j < labelSize; j++)
    {
      if(adj_matrix[i][j] !=0)
        cout << setw(3) << adj_matrix[i][j];
        else
          cout << setw(3) << "-";
    }
    if(i < labelSize - 1)
      cout << endl << "  |" << endl;
  }
}
