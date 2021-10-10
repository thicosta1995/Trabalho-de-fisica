#include "test.h"

class exercicio2 : public Test //voc� cria a sua classe derivada da classe base Test
{
public:
	exercicio2() {
		// Aqui no construtor voc� inicializa a cena

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


			CreateCircle(0.1, 1, b2Vec2(-40, 0));
		}


	}
	void CreateCircle(float density, int radius, b2Vec2 position)
	{
		b2Body* circleObj;


		ba.type = b2_dynamicBody;
		ba.position = position;
		ba.angle += 45;
		bala = m_world->CreateBody(&ba);

		b2CircleShape circle;
		circle.m_radius = radius;

		b2FixtureDef fd;
		fd.shape = &circle;
		fd.density = density;
		fd.restitution = 0.0f;

		bala->CreateFixture(&fd);

	}
	void Keyboard(int key) override
	{
		switch (key)
		{
		case GLFW_KEY_SPACE:
		{	b2Vec2 f = bala->GetWorldVector(b2Vec2(50000.0f, 0.0f));
		b2Vec2 p = bala->GetWorldPoint(b2Vec2(0.0f, 5.0f));
		bala->ApplyForce(f, p, true);

		break;

		}
		case GLFW_KEY_MINUS:
		{

			ba.angle += i;
		}
		}




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
		return new exercicio2;
	}

	b2Body* bala;
	b2BodyDef ba;
	float  i = 1;
};

//Aqui fazemos o registro do novo teste 
static int testIndex = RegisterTest("Examples", "MyTest", exercicio2::Create);