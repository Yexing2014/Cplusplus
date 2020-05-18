#pragma once
class CKomplex {
public:
	CKomplex();
	~CKomplex();
	
	void setReal(double real);
	void setImg(double img);
	double getReal();
	double getImg();

	void add(CKomplex A, CKomplex B);
	void selfadd(CKomplex A);
	void mul(CKomplex A, CKomplex B);
	void mul_mitselb(CKomplex A);

private:
	double mreal;
	double mimg;
};

CKomplex::CKomplex()
{
	mreal = 0.0;
	mimg = 0.0;
}

CKomplex::~CKomplex()
{
}

void CKomplex::setReal(double real)
{
	mreal = real;
}

void CKomplex::setImg(double img)
{
	mimg = img;
}

double CKomplex::getReal()
{
	return mreal;
}

double CKomplex::getImg()
{
	return mimg;
}

void CKomplex::add(CKomplex A, CKomplex B)
{
	mreal = A.mreal + B.mreal;
	mimg = A.mimg + B.mimg;
}

void CKomplex::selfadd(CKomplex A)
{
	mreal  += A.mreal;
	mimg += A.mimg;
}

void CKomplex::mul(CKomplex A, CKomplex B)
{
	mreal = A.mreal *B.mreal - A.mimg*B.mimg;
	mimg = A.mimg*B.mreal + A.mreal*B.mimg;
}

void CKomplex::mul_mitselb(CKomplex A)
{
	mreal = A.mreal*mreal - A.mimg*mimg;
	mimg = A.mimg*mreal + A.mreal*mimg;
}