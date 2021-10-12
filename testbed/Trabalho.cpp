#include "test.h"
#include <iostream>
#include <list>

class Trabalho : public Test //voc� cria a sua classe derivada da classe base Test
{
public:
	Trabalho() {
		//BOLA
		CreateBall(1.0f, 1.0f, b2Vec2(-5.5, 2.0), 0);
		CreateMap();
	}

	void CreateMap()
	{
		//PAREDES
		parede = CreateWall(b2Vec2(0.0f, 40.0f), -40, 0);
		parede1 = CreateWall(b2Vec2(0.0f, 40.0f), 30, 0);
		chao = CreateWall(b2Vec2(70.0f, 0.0f), -40, 0);
		teto = CreateWall(b2Vec2(70.0f, 0.0f), -40, 40);
		//PINOS
		//1 fila
		CreateCircle(0.1, 1, b2Vec2(-10.0, 32.0), 0);
		CreateCircle(0.1, 1, b2Vec2(-7.0, 32.0), 0);
		CreateCircle(0.1, 1, b2Vec2(-4.0, 32.0), 0);
		CreateCircle(0.1, 1, b2Vec2(-1.0, 32.0), 0);
		//2 fila
		CreateCircle(0.1, 1, b2Vec2(-8.5, 29.0), 0);
		CreateCircle(0.1, 1, b2Vec2(-5.5, 29.0), 0);
		CreateCircle(0.1, 1, b2Vec2(-2.5, 29.0), 0);
		//3 fila
		CreateCircle(0.1, 1, b2Vec2(-7.0, 26.0), 0);
		CreateCircle(0.1, 1, b2Vec2(-4.0, 26.0), 0);
		//4 fila
		CreateCircle(0.1, 1, b2Vec2(-5.5, 23.0), 0);
		//obstaculos
		CreateObstaculos(b2Vec2(10, 20), b2Vec2(10, 12), b2Vec2(0.0, 0.0));
		CreateObstaculos(b2Vec2(-15, 20), b2Vec2(-10, 12), b2Vec2(0.0, 0.0));
	}

	b2Body* CreateWall(b2Vec2 position, int x, int y)
	{
		b2Body* body;
		b2BodyDef bd;
		bd.position.Set(x, y);
		body = m_world->CreateBody(&bd);

		b2EdgeShape shape;
		shape.SetTwoSided(position, b2Vec2(0.0f, 0.0f));

		b2FixtureDef fd;
		fd.shape = &shape;
		body->CreateFixture(&fd);
		return body;
	}

	b2Body* CreateCircle(float density, int radius, b2Vec2 position, float gravidade)
	{
		b2Body* circleObj;
		b2BodyDef ba;

		ba.type = b2_dynamicBody;
		ba.position = position;
		
		circleObj = m_world->CreateBody(&ba);
		circleObj->SetGravityScale(gravidade);
		b2CircleShape circle;
		circle.m_radius = radius;
		
		b2FixtureDef fd;
		fd.shape = &circle;

		fd.density = density;
		fd.restitution = 0.0f;

		circleObj->CreateFixture(&fd);

		pinos.push_back(circleObj);

		return circleObj;
	}

	void CreateBall(float density, int radius, b2Vec2 position, float gravidade)
	{
		ballBodyDef.type = b2_dynamicBody;
		ballBodyDef.position = position;
		ballBodyDef.angle = 5;
		ballBody = m_world->CreateBody(&ballBodyDef);
		ballBody->SetGravityScale(gravidade);
		b2CircleShape circle;
		circle.m_radius = radius;

		b2FixtureDef fd;
		fd.shape = &circle;

		fd.density = density;
		fd.restitution = 0.0f;

		ballBody->CreateFixture(&fd);
	}

	void CreateObstaculos(b2Vec2 position, b2Vec2 pontoIncical, b2Vec2 pontoFinal)
	{
		b2Body* obstaculos;
		b2BodyDef bf;
		bf.position = position;
		obstaculos = m_world->CreateBody(&bf);

		b2EdgeShape shape;
		shape.SetTwoSided(pontoIncical,pontoFinal);


		b2FixtureDef fd;
		fd.shape = &shape;
		obstaculos->CreateFixture(&fd);
	}

	void Step(Settings& settings) override
	{
		//Chama o passo da simula��o e o algoritmo de rendering
		Test::Step(settings);

		/*if (glfwGetKey(g_mainWindow, GLFW_KEY_W) == GLFW_PRESS)
		{
		}*/

		std::cout << pinos.size() << std::endl;

		if (gameState == 0)
		{
			//ROTAÇÃO
		}
		else if (gameState == 1)
		{
			//FORÇA
		}
		else if (gameState == 2)
		{
			//NADA
		}
		else if (gameState == 3)
		{
			//DESTRUIR TUDO PARA RESTARTAR LEVEL
			CreateBall(1.0f, 1.0f, b2Vec2(-5.5, 2.0), 0);
			CreateMap();
			gameState = 0;
		}

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

	float gameState = 0; // 0 - Selecao de Rotação || 1 - Selecao de força || 2 - Aguardando finalizar rodada || 3 - Remontar mapa

	float ballAngle = 0;

	std::list<b2Body*> pinos;

	b2BodyDef ballBodyDef;
	b2Body* ballBody;

	b2Body* parede;
	b2Body* chao;
	b2Body* parede1;
	b2Body* teto;	
};

//Aqui fazemos o registro do novo teste 
static int testIndex = RegisterTest("Examples", "Trabalho", Trabalho::Create);