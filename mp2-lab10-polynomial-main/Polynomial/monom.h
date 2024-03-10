#ifndef _TMONOM_H_
#define _TMONOM_H_

#include "list.h"

class TMonomData
{
public:
  double* data; // степень
  double k; // коэффициент
  int dim; // размерность (кол-во переменных)+

  TMonomData(int t);
  TMonomData(double* _data = 0, int _dim = 0, double k = 0);
  TMonomData(TMonomData& _v);

  ~TMonomData();
};

class TMonom : public TListElem<TMonomData>
{// k*x_0^data[0] * x_1^data[1] ... x_(dim-1)^data[dim-1]
protected:

public:
  TMonom(TMonomData _data);
  TMonom(double* _data = 0, int _dim = 0, double k = 0);
  TMonom(TMonom& _v);
  ~TMonom();

  TMonomData& operator *();
  TMonomData& operator *(int);

  double GetK();
  void SetK(double k);

  int GetDim();
  void SetDim(int _dim);

  virtual TMonom* Clone();
  
  bool operator == (const TMonom& _v);
  bool operator != (const TMonom& _v);
  TMonom& operator= (const TMonom& _v);
  TMonom  operator* (const TMonom& _v);
  TMonom  operator/ (const TMonom& _v);
  TMonom* operator+ (const TMonom& _v);
  TMonom* operator- (const TMonom& _v);
  double& operator[] (int i);

  bool operator> (const TMonom& _v);
  bool operator< (const TMonom& _v);

  friend ostream& operator<< (ostream& ostr, const TMonom& A);
  friend istream& operator>> (istream& istr, TMonom A);
};

#endif // _TMONOM_H_