#include "test.h"
#include <string>
#include<iostream>
class Exercicio3 : public Test, b2ContactListener //voc� cria a sua classe derivada da classe base Test
{
public:
	Exercicio3() {
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
			b2BodyDef bQ;
			bQ.type = b2_dynamicBody;

			bQ.fixedRotation = true;
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



		}
	}
	void Begin(b2Contact* contact)
	{
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();
		b2Body* body1 = fixtureA->GetBody();
		b2Body* body2 = fixtureA->GetBody();
		std::cout << gronded;
		gronded = true;
	}
	void End(b2Contact* contact)
	{
		gronded = false;
	}
	void Keyboard(int key) override
	{
		switch (key)
		{
		case GLFW_KEY_SPACE:
		{

			if (gronded == true)
			{
				b2Vec2 f = quadrado->GetWorldVector(b2Vec2(0, 3000.0f));
				b2Vec2 p = quadrado->GetWorldPoint(b2Vec2(10.0F, 5.0f));
				quadrado->ApplyForce(f, p, true);
				break;
			}


		}
		}
	}

	void Step(Settings& settings) override
	{
		if (glfwGetKey(g_mainWindow, GLFW_KEY_D) == GLFW_PRESS)
		{
			b2Vec2 v = quadrado->GetLinearVelocity();
			quadrado->SetLinearVelocity(b2Vec2(2, v.y));

		}
		if (glfwGetKey(g_mainWindow, GLFW_KEY_D) == GLFW_RELEASE)
		{
			b2Vec2 v = quadrado->GetLinearVelocity();
			quadrado->SetLinearVelocity(b2Vec2(0, v.y));
		}


		if (glfwGetKey(g_mainWindow, GLFW_KEY_A) == GLFW_PRESS)
		{
			b2Vec2 v = quadrado->GetLinearVelocity();
			quadrado->SetLinearVelocity(b2Vec2(-2, v.y));

		}
		if (glfwGetKey(g_mainWindow, GLFW_KEY_A) == GLFW_RELEASE)
		{
			b2Vec2 v = quadrado->GetLinearVelocity();
			quadrado->SetLinearVelocity(b2Vec2(0, v.y));
		}
		//Chama o passo da simula��o e o algoritmo de rendering
		Test::Step(settings);

		//show some text in the main screen
		g_debugDraw.DrawString(5, m_textLine, "Este e' um template para os exercicios!! :)");
		m_textLine += 15;
	}

	static Test* Create()  //a classe Test que instancia um objeto da sua nova classe
						   //o autor da Box2D usa um padr�o de projeto chamado Factor
						   //para sua arquitetura de classes
	{

		return new Exercicio3;
	}

	bool gronded = true;
	b2Body* quadrado;
};

//Aqui fazemos o registro do novo teste 
static int testIndex = RegisterTest("Examples", "MyTest", Exercicio3::Create);