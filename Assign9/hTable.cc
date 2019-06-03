/***********************************************
NAME: Luis Aguinaga
ZID:z1811673
ASSIGNMENT: 9
DUE: 11/28/2017
***********************************************/
#include "/home/cs340/progs/17f/p9/hTable.h"
HT::HT(const unsigned& hs)
{
  hTable.resize(hs);
  pTable.resize(hs);
  hsize = TBLSZ;
}

HT::~HT()
{

}

void HT::search(const string& key)
{
  int hashNum = hash(key);
  for(unsigned int i = 0; i < hsize; i++)
  {
    if(?? == key)
    {
      cout << " ==> number: " << setw(4) << hTable[].num
      << " - item: " << hTable[].desc << endl;
    }
  }
  if(?? != key)
    cout << " not in the table." << endl;
}

void HT::insert(const Entry& e)
{
  int hashNum = hash(e.key);
  for (unsigned int i = 0;i < hsize; i++)
  {
    list<Entry>& I = hTable[i];
    if(find_if(hTable.begin(), hTable.end(),[e](key, desc, num) ) == I.cend())
    {
      cout << " entry = " << (hashNum + i) % hsize << endl;
      hTable[i] = e;
      pTable[psize] = &hTable[i];
      psize++;
    }

  }
}

void HT::hTable_print()
{
  for(unsigned int i = 0;i < hsize; i++)
  {
    if(hTable.key != "")
    {
      cout << setw(4) << i << ": " << hTable[i].key << " - "
      << setw(5) << hTable[i].num << "   -   " << hTable.desc << endl;
    }
  }
  cout << endl;
}

void HT::pTable_print()
{
  bool cmp(Entry* p, Entry* q);
  sort(pTable.begin(), pTable.end(), cmp);
  for(unsigned int i = 0; i < psize; i++)
  {
    cout << "  " << pTable[i]->key << " - "
    << right << setw(4) << pTable[i]->num << " - "
    << left << pTable[i]->desc << endl;
  }
  cout << endl;

}
