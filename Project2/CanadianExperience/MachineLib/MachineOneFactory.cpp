#include "stdafx.h"
#include "MachineOneFactory.h"
#include <memory>
#include "MachineActual.h"
#include "Motor.h"
#include "Pulley.h"
#include "Cam.h"
#include "Shape.h"

using namespace Gdiplus;
using namespace std;

CMachineOneFactory::CMachineOneFactory()
{
}


CMachineOneFactory::~CMachineOneFactory()
{
}

shared_ptr<CMachineActual> CMachineOneFactory::CreateMachineOne()
{
	shared_ptr<CMachineActual> machine = make_shared<CMachineActual>();

	// The base
	auto base = make_shared<CShape>();
	int wid = 550;
	base->Rectangle(-wid / 2, 0, wid, 40);
	base->SetImage(L"images/base.png");
	

	//CMotor motor;
	auto motor = make_shared<CMotor>();
	motor->SetPosition(-190, -40);

	//CMotor body
	auto body = make_shared<CPolygon>();
	body->Rectangle(0, 0, 80, 80);
	body->SetImage(L"images/motor2.png");
	motor->SetBody(body);

	//CMotor shaft
	auto shaft = make_shared<CShape>();
	shaft->SetPosition(-150, -80);
	shaft->Circle(10);
	shaft->SetImage(L"images/shaft.png");
	motor->SetShaft(shaft);

	//Shapes
	auto flag = make_shared<CShape>();
	//flag->CenteredSquare(50);
	flag->AddPoint(0, 0);
	flag->AddPoint(-4, 0);
	flag->AddPoint(-4, -60);
	flag->AddPoint(-20, -50);
	flag->AddPoint(-50, -50);
	flag->AddPoint(-50, -90);
	flag->AddPoint(0, -90);
	flag->SetImage(L"images/flag.png");
	//flag->SetColor(Color::Red);
	flag->SetPosition(-200, -170);

	auto stand1 = make_shared<CShape>();
	stand1->Rectangle(0, 0, 20, 130);
	stand1->SetColor(Color::MediumBlue);
	stand1->SetPosition(-209,-40);

	auto stand2 = make_shared<CShape>();
	stand2->Rectangle(0, 0, 20, 130);
	stand2->SetColor(Color::Firebrick);
	stand2->SetPosition(-90, -40);

	auto stand3 = make_shared<CShape>();
	stand3->Rectangle(0, 0, 20, 130);
	stand3->SetColor(Color::Firebrick);
	stand3->SetPosition(-20, -40);

	auto stand4 = make_shared<CShape>();
	stand4->Rectangle(0, 0, 20, 130);
	stand4->SetColor(Color::Firebrick);
	stand4->SetPosition(50, -40);

	auto stand5 = make_shared<CShape>();
	stand5->Rectangle(0, 0, 20, 130);
	stand5->SetColor(Color::Firebrick);
	stand5->SetPosition(120, -40);

	auto stand6 = make_shared<CShape>();
	stand6->Rectangle(0, 0, 20, 130);
	stand6->SetColor(Color::Firebrick);
	stand6->SetPosition(190, -40);


	//Pulleys
	auto pulley1 = make_shared<CPulley>(15);
	pulley1->SetImage(L"images/pulley2.png");
	pulley1->SetPosition(-150, -80);
	motor->AddSink(pulley1);

	auto pulley2 = make_shared<CPulley>(40);
	pulley2->SetPosition(-200, -170);
	pulley2->SetImage(L"images/pulley.png");
	pulley1->SetSink(pulley2);
	
	auto pulley3 = make_shared<CPulley>(15);
	pulley3->SetImage(L"images/pulley2.png");
	pulley3->SetPosition(-200, -170);
	pulley2->AddSink(pulley3);
	pulley2->AddSink(flag);

	auto pulley4 = make_shared<CPulley>(30);
	pulley4->SetImage(L"images/pulley.png");
	pulley4->SetPosition(-80, -170);
	pulley3->SetSink(pulley4);

	auto pulley5 = make_shared<CPulley>(30);
	pulley5->SetImage(L"images/pulley.png");
	pulley5->SetPosition(-80, -170);
	pulley5->SetPhase(.25);
	pulley3->SetSink(pulley5);

	auto pulley6 = make_shared<CPulley>(30);
	pulley6->SetImage(L"images/pulley.png");
	pulley6->SetPosition(-10, -170);
	pulley4->SetSink(pulley6);

	auto pulley7 = make_shared<CPulley>(30);
	pulley7->SetImage(L"images/pulley.png");
	pulley7->SetPosition(-10, -170);
	pulley7->SetPhase(.25);
	pulley5->SetSink(pulley7);

	
	
	// Cams

	auto cam = make_shared<CCam>(30, 24);
	cam->SetImage(L"images/hammered-copper1.png", true);
	cam->SetPhase(-0.25);
	cam->SetPosition(-200, -170);
	cam->SetPinSize(5);

	cam->AddPin(1);
	cam->AddPin(2);
	cam->AddPin(4);
	cam->Build();

	auto P1 = make_shared<CShape>();
	P1->Circle(5);
	P1->SetColor(Color::Red);
	P1->SetPosition(-188, -178);
	auto P2 = make_shared<CShape>();
	P2->Circle(5);
	P2->SetColor(Color::Red);
	P2->SetPosition(-56, -187);

	machine->AddComponent(base);
	machine->AddMotor(motor);
	machine->AddComponent(pulley1);
	machine->AddComponent(stand1);
	machine->AddComponent(pulley2);
	machine->AddComponent(pulley3);
	machine->AddComponent(flag);
	machine->AddComponent(stand2);
	machine->AddComponent(stand3);
	machine->AddComponent(stand4);
	machine->AddComponent(stand5);
	machine->AddComponent(stand6);
	machine->AddComponent(pulley4);
	machine->AddComponent(pulley5);
	machine->AddComponent(pulley6);
	machine->AddComponent(pulley7);
	machine->AddComponent(cam);
	machine->AddComponent(P1);
	machine->AddComponent(P2);
	return machine;
}