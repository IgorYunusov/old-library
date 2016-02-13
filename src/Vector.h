/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Vector.h

Purpose:

   RollRat Library

Author:

   12-18-2015:   HyunJun Jeong, Creation

***/

#ifndef _VECTOR_9bf1541fdf7efd41b7b39543fd870ac4_
#define _VECTOR_9bf1541fdf7efd41b7b39543fd870ac4_

#include <cmath>
#include <vector>

#define NORMLIZE_MIN   10e-5

namespace Utility {

	// 그래프그리는 용도가 아닙니다
	// x>=0, y>=0

	class Vector2
	{
		float x, y;

	public:

		Vector2()
			: x(.0), y(.0) {  }

		Vector2(float x, float y)
			: x(x), y(y) { }

		void Set(float x, float y)
			{ this->x = x; this->y = y; }

		Vector2 operator+(const Vector2& vec) const
			{ return Vector2(x + vec.x, y + vec.y); }

		Vector2 operator-(const Vector2& vec) const
			{ return Vector2(x - vec.x, y - vec.y); }

		Vector2 operator*(float v) const
			{ return Vector2(x * v, y * v); }

		Vector2 operator/(float v) const
			{ return Vector2(x / v, y / v); }

		Vector2& operator+=(const Vector2& vec)
			{ x += vec.x, y += vec.y; return *this; }
		
		Vector2& operator-=(const Vector2& vec)
			{ x -= vec.x, y -= vec.y; return *this; }

		Vector2& operator*=(float v)
			{ x *= v, y *= v; return *this; }

		Vector2& operator/=(float v)
			{ x /= v, y /= v; return *this; }
		
		Vector2& operator=(const Vector2& vec)
			{ x = vec.x; y = vec.y; return *this; }

		float magnitude() const
			{ return x * x + y * y; }

		float norm() const
			{ return ::sqrt(x * x + y * y); }
		
		Vector2 clone() const
			{ return Vector2(x, y); }
		
		// +: 시계, -: 반시계
		float cross(const Vector2& vec) const
			{ return x * vec.y - y * vec.x; }

		float dot(const Vector2& vec) const
			{ return x * vec.x + y * vec.y; }

		float gradiant() const
			{ return y / x; }
		
		float gx() const
			{ return this->x; }
		
		float gy() const
			{ return this->y; }

		long lx() const
			{ return (long)this->x; }

		long ly() const
			{ return (long)this->y; }

		float distance(const Vector2& vec) const
		{
			float dx = x - vec.x;
			float dy = y - vec.y;
			return ::sqrt(dx * dx + dy * dy);
		}

		Vector2 normalize() const
		{
			float norm = this->norm();
			if (norm < NORMLIZE_MIN)
				norm = NORMLIZE_MIN;
			return Vector2(x / norm, y / norm);
		}

	};

	class Line2
	{
		Vector2 d_1;
		Vector2 d_2;

	public:

		Line2(const Vector2& vec1, const Vector2& vec2)
			: d_1 (vec1), d_2 (vec2) { }

		Line2(float x1, float y1, float x2, float y2)
			: d_1(x1,y1), d_2(x2,y2) { }

		// 두 직선이 한 점에서 만나나 (평행 x)
		bool iscross(const Line2& l) const
		{
			if ( (ccw(  d_1,   d_2, l.d_1) * ccw(  d_1,   d_2, l.d_2) < .0) &&
				 (ccw(l.d_1, l.d_2,   d_1) * ccw(l.d_1, l.d_2,   d_2) < .0)  )
				 return true;
			return false;
		}

		// 교점
		Vector2 cross(const Line2& l) const
		{
			float a1 = (d_1 - d_2).gradiant();
			float b1 = d_1.gy() - a1 * d_1.gx();

			float a2 = (l.d_1 - l.d_2).gradiant();
			float b2 = l.d_1.gy() - a2 * l.d_1.gx();

			return Vector2((b2 - b1) / (a1 - a2), (a2 * b1 - a1 * b2) / (a2 - a1));
		}

		// 화면크기에 맞게 직선 다듬기
		Line2 straight(float max = 1920., float may = 1080.) const
		{
			float a = (d_1 - d_2).gradiant();
			float b = d_1.gy() - a * d_1.gx();

			float in_x = -b / a;
			float in_y = b;

			float x1, x2, y1, y2;

			if ( in_x >= 0.f )
			{
				if ( in_y <= 0.f )
				{
					x1 = in_x;
					y1 = .0;

					if ( a * max + b > may )
					{
						x2 = (may - b) / a;
						y2 = may;
					}
					else
					{
						x2 = max;
						y2 = a * max + b;
					}

					return Line2(x1, y1, x2, y2);
				}
				else
				{
					return Line2(in_x, .0, .0, in_y);
				}
			}
			else
			{
				x1 = .0;
				y1 = in_y;
				
				if ( a * max + b > may )
				{
					x2 = (may - b) / a;
					y2 = may;
				}
				else
				{
					x2 = max;
					y2 = a * max + b;
				}
				
				return Line2(x1, y1, x2, y2);
			}
		}
		
		// 선분의 각 끝 점을 지나고 선분과 수직인 두 직선 사이에 점이 포함되어있는경우 그 점과 선분의 거리를, 
		// 아니면 선분의 양 끝 점과 점 사이의 거리 중 짧은 거리를 계산합니다.
		float distance(const Vector2& vec) const
		{
			Vector2 a = d_2 - d_1; // AB 벡터
			Vector2 b = vec - d_1; // AC 벡터

			float dot1 = a.dot(b);
			if ( dot1 <= 0 )
				return d_1.distance(vec);

			// w1 = w0 - v
			// dot w1 v = dot (w0 - v) v = (dot w0 v) - (dot v v) 
			float dot2 = a.magnitude();
			if (dot2 <= dot1)
				return d_2.distance(vec);

			return vec.distance(Vector2(d_1 + a * (dot1/dot2)));
		}

		Vector2 g1() const
			{ return d_1; }
		
		Vector2 g2() const
			{ return d_2; }

	private:

		float ccw(const Vector2& v_1, const Vector2& v_2, const Vector2& v_3) const
		{
			return v_2.cross(v_1) + v_1.cross(v_3) + v_3.cross(v_2);
		}

	};

	class Circle2 : public Vector2
	{
		float r;

	public:

		Circle2(float r)
			: r(r) { }

		Circle2(const Vector2& vec)
			: r(vec.norm()), Vector2(vec) { }

		Circle2(float x, float y)
			: Vector2(x, y), r(this->norm()) { }

		Circle2(const Vector2& vec, float r)
			: Vector2(vec), r(r) { }

		Circle2(float x, float y, float r)
			: Vector2(x, y), r(r) { }

		float radius() const
			{ return r; }

		float diameter() const
			{ return r * 2; }

		bool Collision(const Circle2& cir) const
			{ return r + cir.r < distance(cir); }

		bool Collision(const Line2& l) const
			{ return r < l.distance(*this); }

	};

	class Drawer
	{
		std::vector<Line2>   lines;
		std::vector<Circle2> circles;
		std::vector<float> intevals;

	public:

		void clear() { }
		void drawpixel(long x, long y) { }
		void drawcircle(long x0, long y0, long radius) { }
		void drawline(long x1, long y1, long x2, long y2)
		{
			long dx = x2 - x1;
			long dy = y2 - y1;

			for ( int x = x1; x1 < x2; x1++)
			{
				drawpixel(x, y1 + dy * (x - x1) / dx);
			}
		}

		void update()
		{
			moveCircle();
			for (Line2& l : lines)
			{
				drawline((long)l.g1().gx(), (long)l.g1().gy(), (long)l.g2().gx(), (long)l.g2().gy());
			}
			for (Circle2& c : circles)
			{
				drawcircle((long)c.gx(), (long)c.gy(), (long)c.radius());
			}
		}

		void newCircle(float x, float y, float r)
		{
			circles.push_back(Circle2(x, y, r));
		}

		void newLine(float x1, float y1, float x2, float y2)
		{
			lines.push_back(Line2(x1,y1,x2,y2));
		}

		void moveCircle(float acceleration = 9.8f)
		{
			for (int i = 0; i < circles.size(); i++)
			{
				// ?
			}
		}

		bool testCollision(const Circle2& cir, int dis)
		{
			for (int i = 0; i < lines.size(); i++)
			{
				if (cir.Collision(lines[i]))
					return true;
			}
			for (int i = 0; i < circles.size(); i++)
			{
				if ( i != dis )
					if (cir.Collision(circles[i]))
						return true;
			}
			return false;
		}

	};

}

#endif