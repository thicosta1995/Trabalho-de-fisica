#include "test.h"
#include <iostream>


class MyTest : public Test
{
public:
	MyTest() {


		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			bd.position.Set(0, -3);
			ground = m_world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.SetTwoSided(b2Vec2(-40.0f, 0.0f), b2Vec2(30.0f, 0.0f));

			b2FixtureDef fd;
			fd.shape = &shape;

			ground->CreateFixture(&fd);
			b2Body* parede;
			b2BodyDef bq;
			bq.position.Set(-40, -3);
			parede = m_world->CreateBody(&bq);

			b2EdgeShape shape1;
			shape1.SetTwoSided(b2Vec2(0, -0), b2Vec2(0, 43.0f));

			b2FixtureDef f1;
			f1.shape = &shape1;

			parede->CreateFixture(&f1);
			b2Body* parede1;
			b2BodyDef b1;
			b1.position.Set(30, -3);

			parede1 = m_world->CreateBody(&b1);

			b2EdgeShape shape2;
			shape2.SetTwoSided(b2Vec2(0, -0), b2Vec2(0, 43.0f));

			b2FixtureDef f2;
			f2.shape = &shape2;

			parede1->CreateFixture(&f2);
			b2Body* teto;
			b2BodyDef b3;
			b3.position.Set(-20, 40);

			teto = m_world->CreateBody(&b3);

			b2EdgeShape shape3;
			shape3.SetTwoSided(b2Vec2(-20.0f, 0), b2Vec2(50, 0));

			b2FixtureDef f3;
			f3.shape = &shape3;

			teto->CreateFixture(&f3);
			b2Body* rampa;
			b2BodyDef b4;
			b4.position.Set(0, -0);

			rampa = m_world->CreateBody(&b4);

			b2EdgeShape shape4;
			shape4.SetTwoSided(b2Vec2(-30.0f, 0), b2Vec2(20.0f, 20));

			b2FixtureDef f4;
			f4.shape = &shape4;

			rampa->CreateFixture(&f4);
		}


		b2Vec2 gravity(0.0f, -9.8f);
		float x, y, xP, yP, LyP, LxP, LyP1, LxP1;
		int C;
		float D;


		for (int i = 0; i < 10; i++)
		{
			x = RandomFloat(1, 5);
			y = RandomFloat(1, 5);
			C = RandomFloat(1, 5);
			D = RandomFloat(1, 5);
			xP = RandomFloat(-15, 15);
			yP = RandomFloat(-15, 15);
			LxP = RandomFloat(-5, 0);
			LyP = RandomFloat(0, 5);
			LxP1 = RandomFloat(-5, 0);
			LyP1 = RandomFloat(0, 5);

			Linha(b2Vec2(xP, yP), D, b2Vec2(LxP, LyP), b2Vec2(LxP1, LyP1));
			spwanQuadrados(x, y, D, b2Vec2(xP, yP), 0, 0);
			CreateCircle(D, C, b2Vec2(xP, yP));
		}

		float timeStep = 1.0f / 60.0f;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;

	}
	void Keyboard(int key) override
	{
		switch (key)
		{

			float x, y, xP, yP, LyP, LxP, LyP1, LxP1;

			int C;
			float D;
		case GLFW_KEY_Q:
			x = RandomFloat(1, 5);
			y = RandomFloat(1, 5);
			C = RandomFloat(1, 5);
			D = RandomFloat(1, 5);
			xP = RandomFloat(-15, 15);
			yP = RandomFloat(-15, 15);

			spwanQuadrados(x, y, D, b2Vec2(xP, yP), r, T);
			if (r < 1.0)
				r += 0.1;
			if (T < 1.0)
				T += 0.1;

			break;
		case GLFW_KEY_C:
			C = RandomFloat(1, 5);
			D = RandomFloat(1, 5);
			xP = RandomFloat(-15, 15);
			yP = RandomFloat(-15, 15);
			CreateCircle(D, C, b2Vec2(xP, yP));
			break;
		case GLFW_KEY_L:
			D = RandomFloat(1, 5);
			xP = RandomFloat(-15, 15);
			yP = RandomFloat(-15, 15);
			LxP = RandomFloat(-5, 0);
			LyP = RandomFloat(0, 5);
			LxP1 = RandomFloat(-5, 0);
			LyP1 = RandomFloat(0, 5);
			Linha(b2Vec2(xP, yP), D, b2Vec2(LxP, LyP), b2Vec2(LxP1, LyP1));
		}


	}
	void spwanQuadrados(float x, float y, float density, b2Vec2 position, float  restituition, float friction)
	{
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position = position; //origem do objeto
		b2Body* body = m_world->CreateBody(&bodyDef);

		b2PolygonShape box;
		box.SetAsBox(x, y);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &box;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = friction;
		fixtureDef.restitution = restituition;
		body->CreateFixture(&fixtureDef);

	}

	void CreateCircle(float density, int radius, b2Vec2 position)
	{
		b2Body* circleObj;

		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position = position;
		circleObj = m_world->CreateBody(&bd);

		b2CircleShape circle;
		circle.m_radius = radius;

		b2FixtureDef fd;
		fd.shape = &circle;
		fd.density = density;
		fd.restitution = 0.0f;

		circleObj->CreateFixture(&fd);
	}
	void Linha(b2Vec2 position, float density, b2Vec2 tamanhoMin, b2Vec2 tamanhoMax)
	{
		b2Body* linhas;

		b2BodyDef bt;
		bt.type = b2_dynamicBody;
		bt.position = position;
		linhas = m_world->CreateBody(&bt);
		b2EdgeShape shape;
		shape.SetTwoSided(b2Vec2(tamanhoMin), b2Vec2(tamanhoMax));
		b2FixtureDef fq;
		fq.shape = &shape;
		fq.density = density;
		fq.restitution = 0;
		linhas->CreateFixture(&fq);
	}

	void Step(Settings& settings) override
	{
		//Chama o passo da simula��o e o algoritmo de rendering
		Test::Step(settings);

		//show some text in the main screen
		g_debugDraw.DrawString(5, m_textLine, "Este e' um template para os exercicios!! :)");
		m_textLine += 15;
	}

	static Test* Create()

	{
		return new MyTest;
	}
	bool aQuadrado = false;
	float r = 0;
	float T = 0;
};


static int testIndex = RegisterTest("Examples", "MyTest", MyTest::Create);