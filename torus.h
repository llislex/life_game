#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class torus
{
	vector<T> m_content;
	int m_w, m_h;
	int ringCoordinate(int v, int maxV) const;
public:
	torus(int w, int h);
	void set(const T& value, int x, int y);
	T get(int x, int y) const;
	int width() const {return m_w;}
	int height() const {return m_h;}

    //friend ostream& operator << <T> (ostream& output, const torus<T> & v);
};

template <class T>
torus<T>::torus(int w, int h)
:m_w(w), m_h(h)
{
	m_content.resize(m_w * m_h);
}

template <class T>
int torus<T>::ringCoordinate(int v, int maxV) const
{
	if(v < 0)
	{
		int absV = abs(v) % maxV;
		return absV == 0 ? absV : maxV - absV;
	}
	return v % maxV;
}

template <class T>
T torus<T>::get(int x, int y) const
{
	x = ringCoordinate(x, m_w);
	y = ringCoordinate(y, m_h);
	return m_content[x + y * m_w];
}

template <class T>
void torus<T>::set(const T& value, int x, int y)
{
	x = ringCoordinate(x, m_w);
	y = ringCoordinate(y, m_h);
	m_content[x + y * m_w] = value;
}

/*
template <class T>
ostream& operator<<(ostream& output, const torus<T>& v)
{
	for(int y = 0; y < v.m_h; ++y)
	{
		for(int x = 0; x < v.m_w; ++x)
		{
			output << v.m_content[x + y * v.m_w] << " ";
		}	
		output << endl;
	}
	return output;
}
*/
