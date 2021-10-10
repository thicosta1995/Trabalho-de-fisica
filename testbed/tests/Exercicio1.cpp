#include "test.h"

class Exercicio1 : public Test //voc� cria a sua classe derivada da classe base Test
{
public:
	Exercicio1() {
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

			b2BodyDef bQ;
			bQ.type = b2_dynamicBody;
			bQ.position.Set(-20.f, 1.f); //origem do objeto

			quadrado = m_world->CreateBody(&bQ);

			b2PolygonShape box;
			box.SetAsBox(0.5, 3.0);
			b2FixtureDef fixtureDef;
			fixtureDef.shape = &box;
			fixtureDef.density = 1;
			fixtureDef.friction = 0;
			fixtureDef.restitution = 0;
			quadrado->CreateFixture(&fixtureDef);


			float x = -20;

			ground->CreateFixture(&fd);
			for (int i = 0; i < 5; i++)
			{
				x += 3;
				spwanQuadrados(0.5f, 3.0f, 1.0, b2Vec2(x, 1), 0, 0);
			}
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
		fixtureDef.density = 1;
		fixtureDef.friction = friction;
		fixtureDef.restitution = restituition;
		body->CreateFixture(&fixtureDef);

	}
	void Step(Settings& settings) override
	{

		if (glfwGetKey(g_mainWindow, GLFW_KEY_W) == GLFW_PRESS)
		{
			b2Vec2 f = quadrado->GetWorldVector(b2Vec2(50.0f, 0));
			b2Vec2 p = quadrado->GetWorldPoint(b2Vec2(0.0f, 5.0f));
			quadrado->ApplyForce(f, p, true);
		}
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
		return new Exercicio1;
	}
	b2Body* quadrado;
};

//Aqui fazemos o registro do novo teste 
static int testIndex = RegisterTest("Examples", "MyTest", Exercicio1::Create);