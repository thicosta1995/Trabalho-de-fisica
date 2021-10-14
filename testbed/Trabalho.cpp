#include "test.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include "imgui/imgui.h"
#include <chrono>

class Trabalho : public Test //voc� cria a sua classe derivada da classe base Test
{
public:
	Trabalho() {
		//BOLA
		CreateBall(1.0f, 1.0f, b2Vec2(-5.5, 2.0), 0);
		CreatePins();
		CreateMap();
	}

	void CreatePins()
	{
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
		//
		pinosPos.push_back(b2Vec2(-5.5, 23.0));
		pinosPos.push_back(b2Vec2(-4.0, 26.0));
		pinosPos.push_back(b2Vec2(-7.0, 26.0));
		pinosPos.push_back(b2Vec2(-2.5, 29.0));
		pinosPos.push_back(b2Vec2(-5.5, 29.0));
		pinosPos.push_back(b2Vec2(-8.5, 29.0));
		pinosPos.push_back(b2Vec2(-1.0, 32.0));
		pinosPos.push_back(b2Vec2(-4.0, 32.0));
		pinosPos.push_back(b2Vec2(-7.0, 32.0));
		pinosPos.push_back(b2Vec2(-10.0, 32.0));

		pinoStatus.push_back(false);
		pinoStatus.push_back(false);
		pinoStatus.push_back(false);
		pinoStatus.push_back(false);
		pinoStatus.push_back(false);
		pinoStatus.push_back(false);
		pinoStatus.push_back(false);
		pinoStatus.push_back(false);
		pinoStatus.push_back(false);
		pinoStatus.push_back(false);
	}

	void CreateMap()
	{

		for (int i = 0; i < pinoStatus.size(); i++)
		{
			pinoStatus[i] = false;
		}

		plays = 3;
		ballBody->SetTransform(b2Vec2(-5.5, 2.0), 0);
		ballBody->SetLinearVelocity(b2Vec2(0, 0));
		ballBody->SetAngularVelocity(0);
		//PAREDES
		CreateWall(b2Vec2(0.0f, 40.0f), -40, 0, 1);
		CreateWall(b2Vec2(0.0f, 40.0f), 30, 0, 1);
		CreateWall(b2Vec2(70.0f, 0.0f), -40, 0, 1);

		targetArea = CreateBox(-35, 5, b2Vec2(-5.0f, 45.0f));

		//obstaculos
		CreateObstaculos(b2Vec2(10, 20), b2Vec2(10, 12), b2Vec2(0.0, 0.0), 1);
		CreateObstaculos(b2Vec2(-15, 20), b2Vec2(-10, 12), b2Vec2(0.0, 0.0), 1);
	}

	void CreateMap2()
	{
		for (int i = 0; i < pinoStatus.size(); i++)
		{
			pinoStatus[i] = false;
		}

		plays = 3;
		ballBody->SetTransform(b2Vec2(-5.5, 2.0), 0);
		ballBody->SetLinearVelocity(b2Vec2(0, 0));
		ballBody->SetAngularVelocity(0);
		//PAREDES
		CreateWall(b2Vec2(0.0f, 10.0f), -40, 0, 1);
		CreateWall(b2Vec2(0.0f, 10.0f), -40, 20, 1);

		CreateWall(b2Vec2(0.0f, 10.0f), 30, 0, 1);
		CreateWall(b2Vec2(0.0f, 10.0f), 30, 20, 1);

		CreateWall(b2Vec2(70.0f, 0.0f), -40, 0, 1);

		targetArea = CreateBox(-35, 5, b2Vec2(-5.0f, 45.0f));

		//obstaculos
		CreateObstaculos(b2Vec2(0, 20), b2Vec2(15, 0), b2Vec2(0.0, 0.0), 1);
		CreateObstaculos(b2Vec2(-25, 20), b2Vec2(15, 0), b2Vec2(0.0, 0.0), 1);

		//CreateObstaculos(b2Vec2(-15, 20), b2Vec2(-10, 12), b2Vec2(0.0, 0.0));
	}

	void CreateMap3()
	{
		for (int i = 0; i < pinoStatus.size(); i++)
		{
			pinoStatus[i] = false;
		}

		plays = 3;
		ballBody->SetTransform(b2Vec2(-5.5, 2.0), 0);
		ballBody->SetLinearVelocity(b2Vec2(0, 0));
		ballBody->SetAngularVelocity(0);
		//PAREDES
		CreateWall(b2Vec2(0.0f, 40.0f), -40, 0, 1);
		CreateWall(b2Vec2(0.0f, 40.0f), 30, 0, 1);
		CreateWall(b2Vec2(70.0f, 0.0f), -40, 0, 1);

		targetArea = CreateBox(-35, 5, b2Vec2(-5.0f, 45.0f));

		//obstaculos
		CreateObstaculos(b2Vec2(-10, 39.5f), b2Vec2(10, 0), b2Vec2(0.0, 0.0), 1);
		CreateObstaculos(b2Vec2(-30, 39.5f), b2Vec2(10, 0), b2Vec2(0.0, 0.0), 1);
		CreateObstaculos(b2Vec2(10, 39.5f), b2Vec2(10, 0), b2Vec2(0.0, 0.0), 1);

		CreateObstaculos(b2Vec2(10, 10), b2Vec2(0, 0), b2Vec2(0.0, 15.0), 2);
		CreateObstaculos(b2Vec2(-20, 10), b2Vec2(0, 0), b2Vec2(0.0, 15.0), 2);
	}


	b2Body* CreateWall(b2Vec2 position, int x, int y, int restitution)
	{
		b2Body* body;
		b2BodyDef bd;
		bd.position.Set(x, y);
		body = m_world->CreateBody(&bd);

		b2EdgeShape shape;
		shape.SetTwoSided(position, b2Vec2(0.0f, 0.0f));

		b2FixtureDef fd;
		fd.shape = &shape;
		fd.restitution = restitution;
		walls.push_back(body);

		body->CreateFixture(&fd);
		return body;
	}

	b2Body* CreateBox(float height, float width, b2Vec2 position)
	{
		b2BodyDef boxObj;
		boxObj.type = b2_dynamicBody;
		boxObj.position = position;
		b2Body* body = m_world->CreateBody(&boxObj);

		b2PolygonShape box;

		box.SetAsBox(height, width);
		b2FixtureDef fd;
		fd.shape = &box;
		fd.isSensor = true;
		targetAreaFd = body->CreateFixture(&fd);

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
		fd.restitution = 0.5f;

		pinosfd.push_back(circleObj->CreateFixture(&fd));

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
		fd.restitution = 0.5f;


		fixturedef = ballBody->CreateFixture(&fd);
	}

	void CreateObstaculos(b2Vec2 position, b2Vec2 pontoIncical, b2Vec2 pontoFinal, int restitution)
	{
		b2Body* obstaculos;
		b2BodyDef bf;
		bf.position = position;
		obstaculos = m_world->CreateBody(&bf);

		b2EdgeShape shape;
		shape.SetTwoSided(pontoIncical,pontoFinal);

		b2FixtureDef fd;
		fd.shape = &shape;
		fd.restitution = restitution;
		obstacles.push_back(obstaculos);
		obstaculos->CreateFixture(&fd);
	}

	void ClearMap()
	{
		for (int i = 0; i < walls.size(); i++)
		{
			m_world->DestroyBody(walls[i]);
		}

		for (int i = 0; i < obstacles.size(); i++)
		{
			m_world->DestroyBody(obstacles[i]);
		}

		walls.clear();
		obstacles.clear();

		for (int i = 0; i < pinos.size(); i++)
		{
			pinos[i]->SetTransform(pinosPos[i], 0);
			pinos[i]->SetLinearVelocity(b2Vec2(0, 0));
			pinos[i]->SetAngularVelocity(0);
		}
	}

	void BeginContact(b2Contact* contact) override
	{
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		for (int i = 0; i < pinosfd.size(); i++)
		{
			if (fixtureA == pinosfd[i] || fixtureB == pinosfd[i])
			{
				if (fixtureA == targetAreaFd || fixtureB == targetAreaFd)
				{
					pinoStatus[i] = true;
					std::cout << "COLIDIU";
					balls--;

					
					points++;
				}
			}
		}
	}

	void Keyboard(int key) override
	{
		switch (key)
		{
			case GLFW_KEY_SPACE:
			{
				if (gameState == 0)
				{
					gameState = 1;
				}
				else if (gameState == 1)
				{
					b2Vec2 f = ballBody->GetWorldVector(b2Vec2(force, 0.0f));
					b2Vec2 p = ballBody->GetWorldPoint(b2Vec2(0.0f, 5.0f));
					ballBody->ApplyForce(f, p, true);
					force = 1000;
					gameState = 2;
				}
			}
		}
	}

	void ResetGame()
	{
		ClearMap();
		CreateMap();
		level = 1;
		points = 0;
		gameState = 0;
	}

	void Step(Settings& settings) override
	{
		//Chama o passo da simula��o e o algoritmo de rendering
		Test::Step(settings);

		if (gameState == 0)
		{
			ballBody->SetTransform(ballBody->GetWorldCenter(), ballAngle);
			ballAngle += 0.05;

			if (glfwGetKey(g_mainWindow, GLFW_KEY_D) == GLFW_RELEASE)
			{
				b2Vec2 v = ballBody->GetLinearVelocity();
				ballBody->SetLinearVelocity(b2Vec2(0, v.y));
			}
			if (glfwGetKey(g_mainWindow, GLFW_KEY_A) == GLFW_PRESS)
			{
				b2Vec2 v = ballBody->GetLinearVelocity();
				ballBody->SetLinearVelocity(b2Vec2(-20, v.y));
			}
			if (glfwGetKey(g_mainWindow, GLFW_KEY_A) == GLFW_RELEASE)
			{
				b2Vec2 v = ballBody->GetLinearVelocity();
				ballBody->SetLinearVelocity(b2Vec2(0, v.y));
			}
			if (glfwGetKey(g_mainWindow, GLFW_KEY_D) == GLFW_PRESS)
			{
				b2Vec2 v = ballBody->GetLinearVelocity();
				ballBody->SetLinearVelocity(b2Vec2(20, v.y));
			}
		}
		else if (gameState == 1)
		{
			if (force < 5000)
			{
				force += 40;
			}
			else
			{
				force = 1000;
			}
		}
		else if (gameState == 2)
		{
			timer++;

			if (timer == 500)
			{
				gameState = 3;
				timer = 0;

				if (points == 10)
				{
					ClearMap();
					level++;


					if (level == 2)
					{
						points = 0;
						CreateMap2();
					}
					else if (level == 3)
					{
						points = 0;
						CreateMap3();
					}
					else
					{
						ResetGame();
					}

					gameState = 0;
				}
				else if (plays == 0)
				{
					ResetGame();
				}
			}
		}
		else if (gameState == 3)
		{
			for (int i = 0; i < pinos.size(); i++)
			{
				if (pinoStatus[i] == false)
				{
					pinos[i]->SetTransform(pinosPos[i], 0);
					pinos[i]->SetLinearVelocity(b2Vec2(0, 0));
					pinos[i]->SetAngularVelocity(0);
				}
			}

			ballBody->SetTransform(b2Vec2(-5.5, 2.0), 0);
			ballBody->SetLinearVelocity(b2Vec2(0, 0));
			ballBody->SetAngularVelocity(0);
			
			if (plays > 0)
			{
				plays--;
			}
			
			gameState = 0;
		}

		//show some text in the main screen
		g_debugDraw.DrawString(5, m_textLine, "TRABALHO GRAU A :)");
		m_textLine += 15;
	}

	
	void UpdateUI() override
	{
		ImGui::SetNextWindowPos(ImVec2(10.0f, 100.0f));
		ImGui::SetNextWindowSize(ImVec2(260.0f, 130.0f));
		ImGui::Begin("Game Informations", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);

		if (ImGui::SliderFloat("FORCE", &force, 1000, 5000, "%.0f"))
		{
			force = m_joint->SetLength(force);
		}

		if (ImGui::SliderFloat("POINTS", &points, 0, 10, "%.0f"))
		{
			points = m_joint->SetLength(points);
		}

		if (ImGui::SliderFloat("PLAYS", &plays, 1, 3, "%.0f"))
		{
			plays = m_joint->SetLength(plays);
		}

		if (ImGui::SliderFloat("LEVEL", &level, 1, 3, "%.0f"))
		{
			level = m_joint->SetLength(level);
		}

		ImGui::End();
	}

	static Test* Create()  //a classe Test que instancia um objeto da sua nova classe
						   //o autor da Box2D usa um padr�o de projeto chamado Factory
						   //para sua arquitetura de classes
	{
		return new Trabalho;
	}

	float gameState = 0; // 0 - Selecao de Rotação || 1 - Selecao de força || 2 - Aguardando finalizar rodada || 3 - Remontar mapa
	float ballAngle = 0;

	std::vector<b2Body*> pinos;
	std::vector<b2Fixture*> pinosfd;
	std::vector<b2Vec2> pinosPos;
	std::vector<bool> pinoStatus;

	float timer = 0;

	b2BodyDef ballBodyDef;
	b2Body* ballBody; 
	std::vector<b2Body*> walls;
	std::vector<b2Body*> obstacles;

	b2Fixture* fixturedef;
	b2Fixture* targetAreaFd;

	b2Body* targetArea;

	b2DistanceJoint* m_joint;

	float rotation = 0;
	float force = 1000;
	float points = 0;
	float balls = 10;
	float plays;
	float level = 1;
};

//Aqui fazemos o registro do novo teste 
static int testIndex = RegisterTest("Examples", "Trabalho", Trabalho::Create);