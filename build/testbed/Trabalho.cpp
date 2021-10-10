#include "test.h"

class Trabalho : public Test //voc� cria a sua classe derivada da classe base Test
{
public:
	Trabalho() {
		// Aqui no construtor voc� inicializa a cena
		b2BodyDef bd;
		bd.position.Set(-40, 0);
		parede = m_world->CreateBody(&bd);

		b2EdgeShape shape;
		shape.SetTwoSided(b2Vec2(0.0f,40.0f), b2Vec2(0.0f, 0.0f));

		b2FixtureDef fd;
		fd.shape = &shape;
		parede->CreateFixture(&fd);

		b2BodyDef bq;
		bq.position.Set(30, 0);
		parede1 = m_world->CreateBody(&bq);

		b2EdgeShape shape1;
		shape1.SetTwoSided(b2Vec2(0.0f, 40.0f), b2Vec2(0.0f, 0.0f));

		b2FixtureDef fq;
		fq.shape = &shape1;
		parede1->CreateFixture(&fq);

		b2BodyDef bb;
		bb.position.Set(-40, -0);
		chao = m_world->CreateBody(&bb);

		b2EdgeShape shape2;
		shape2.SetTwoSided(b2Vec2(70.0f, 0.0f), b2Vec2(0.0f, 0.0f));

		b2FixtureDef fb;
		fb.shape = &shape2;
		chao->CreateFixture(&fb);

		b2BodyDef bt;
		bt.position.Set(-40, 40);
		teto = m_world->CreateBody(&bt);

		b2EdgeShape shape3;
		shape3.SetTwoSided(b2Vec2(70.0f, 0.0f), b2Vec2(0.0f, 0.0f));

		b2FixtureDef ft;
		ft.shape = &shape3;
		teto->CreateFixture(&ft);
		CreateCircle(1.0f,1.0f,b2Vec2(10.0,2.0));




	}
	void CreateCircle(float density, int radius, b2Vec2 position)
	{
		b2Body* circleObj;
		b2BodyDef ba;

		ba.type = b2_dynamicBody;
		ba.position = position;
		
		circleObj = m_world->CreateBody(&ba);
		circleObj->SetGravityScale(-1);
		b2CircleShape circle;
		circle.m_radius = radius;
		
		b2FixtureDef fd;
		fd.shape = &circle;

		fd.density = density;
		fd.restitution = 0.0f;

		circleObj->CreateFixture(&fd);

	}
	void Step(Settings& settings) override
	{
		//Chama o passo da simula��o e o algoritmo de rendering
		Test::Step(settings);

		//show some text in the main screen
		g_debugDraw.DrawString(5, m_textLine, "Este e' um template para os exercicios!! :)");
		m_textLine += 15;
	}

	static Test* Create()  //a classe Test que instancia um objeto da sua nova classe
						   //o autor da Box2D usa um padr�o de projeto chamado Factory
						   //para sua arquitetura de classes
	{
		return new Trabalho;
	}

	b2Body* parede;
	b2Body* chao;
	b2Body* parede1;
	b2Body* teto;
};

//Aqui fazemos o registro do novo teste 
static int testIndex = RegisterTest("Examples", "Trabalho", Trabalho::Create);