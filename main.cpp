/*
Напишите базовый класс Device, который будет описывать портативные устройства. 
Для этого класса создайте закрытый целочисленный член _batteryLife, 
который будет описывать время работы аккумулятора устройства, а также функцию ShowSpec(),
которая выводит, сколько времени может работать девайс. Создайте дочерний класс Player,
добавьте в него целочисленный закрытый член _totalTracks и функцию ShowTotalTracks(),
которая показывает, сколько треков можно записать в плеер.

Перепишите базовые классы Device и Player так,
чтобы класс Player переопределял функцию ShowSpec,
и выводил на консоль сообщение с информацией о времени работы
аккумулятора и количество треков, которое можно хранить в плеере.

Создайте абстрактный класс IElectronics, 
в котором будет чистая виртуальная функция void ShowSpec.
Дополните ваш магазин электроники и создайте дополнительный класс Appliances(бытовая техника),
который будет содержать целочисленную характеристику weight — вес бытовой техники.
Перепишите классы Appliances(бытовая техника) и Device так, чтобы они наследовались от IElectronics.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class IElectronics
{
public:
	virtual void ShowSpec() = 0;
	virtual ~IElectronics() = default;
};

class Appliances : public IElectronics
{
private:
	float _weight;
public:
	Appliances(float weight) : _weight(weight) {}
	void ShowSpec() override
	{
		cout << "Weight appliances: " << _weight << endl;
	}
};
class Device : public IElectronics
{
protected:
	int _batteryLife;
public:
	Device(int batteryLife) : _batteryLife(batteryLife) {}
	virtual void ShowSpec() override
	{
		cout << "Time work device: " << endl;
	}

};
class Player : public Device
{
private:
	int _totalTrack;
public:
	Player(int batteryLife, int totalTrack) : Device(batteryLife), _totalTrack(totalTrack)
	{

	}
	void ShowTotalTrack()
	{
		cout << "Total track in device: " << endl;
	}
	void ShowSpec()
	{
		cout << "Time work device: " << _batteryLife << "Total track in device: " << _totalTrack << endl;
	}
};


int main()
{


}