#include<iostream>
#include<string>
using namespace std;

class circle
{
public:
	void set_cx(double x)
	{
		circle_center_x = x;
	}
	double get_cx()
	{
		return circle_center_x;
	}
	void set_cy(double y)
	{
		circle_center_y = y;
	}
	double get_cy()
	{
		return circle_center_y;
	}
	void set_cr(double r)
	{
		circle_center_r = r;
	}
	double get_cr()
	{
		return circle_center_r;
	}
private:
	double circle_center_x;
	double circle_center_y;
	double circle_center_r;
};

class point
{
public:
	void set_px(double x)
	{
		point_x = x;
	}
	double get_px()
	{
		return point_x;
	}
	void set_py(double y)
	{
		point_y = y;
	}
	double get_py()
	{
		return point_y;
	}
private:
	double point_x;
	double point_y;
};

//判断点与圆的位置关系
void judge(circle &c, point &p)
{
	double det2 = (c.get_cx() - p.get_px())*(c.get_cx() - p.get_px()) +
		(c.get_cy() - p.get_py())*(c.get_cy()-p.get_py());
	double r2 = c.get_cr()*c.get_cr();
	if (det2 == r2)
		cout << "点在圆上" << endl;
	else if (det2 > r2)
		cout << "点在圆外" << endl;
	else
		cout << "点在圆内" << endl;
}
int main()
{
	circle c1;
	c1.set_cx(0.0);
	c1.set_cy(0.0);
	c1.set_cr(1.0);
	point p1;
	p1.set_px(1.0);
	p1.set_py(0.0);

	judge(c1, p1);
	system("pause");
	return 0;
}