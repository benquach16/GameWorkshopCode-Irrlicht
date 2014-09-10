// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <irrlicht.h>
#include "scene.h"
#include "gamescene.h"
#include "menuscene.h"
#include "tutorialscene.h"
#include "globals.h"

#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "irrklang.lib")

using namespace irr;
using namespace irrklang;
using namespace video;
using namespace core;
using namespace gui;
using namespace scene;


int _tmain(int argc, char* argv[])
{
	globals::screenX = 640;
	globals::screenY = 480;
	globals::device = createDevice(video::EDT_DIRECT3D9, dimension2d<u32>(globals::screenX, globals::screenY));
	globals::sound = createIrrKlangDevice();
	globals::sound->play2D("Resources/Sound/music.wav", true);	
	Scene *currentScene;
	currentScene = new MenuScene;
	int switchTimer;
	bool endGame = false;
	while (globals::device->run())
	{
		globals::device->getVideoDriver()->beginScene(true, true, SColor(255, 100, 101, 140));
		Scene::E_SCENE_RETURN_CODE retCode = currentScene->run();

		globals::device->getSceneManager()->drawAll();
		globals::device->getGUIEnvironment()->drawAll();

		globals::device->getVideoDriver()->endScene();
		if (retCode == Scene::SWITCH_TOGAME)
		{

				delete currentScene;
				currentScene = new GameScene;
			
		}
		if (retCode == Scene::SWITCH_TOTUTORIAL)
		{
			delete currentScene;
			currentScene = new TutorialScene;
		}
		if (retCode == Scene::SWITCH_TOMENU)
		{
			if (!endGame)
			{
			switchTimer = globals::device->getTimer()->getTime() + 4000;
			endGame = true;
			}

			if (switchTimer <= globals::device->getTimer()->getTime())
			{
				delete currentScene;
				endGame = false;
				currentScene = new MenuScene;
			}
		}
		if (retCode == Scene::EXIT_GAME)
		{
			break;
		}
	}
	delete currentScene;
	return 0;
}

