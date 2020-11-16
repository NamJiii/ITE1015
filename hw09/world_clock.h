#include <string>
#include <iostream>

using namespace std;

class WorldClock
{
public:

	void Tick(int seconds = 1);
	bool SetTime(int hour, int minute, int second);
	// �߸��� �� �Է½� false �����ϰ� ���� �ð��� �ٲ��� ����.

	int hour() const;
	int minute() const;
	int second() const;

private:
	int second_, minute_, hour_;
};

struct InvalidTimeException
{
	string input_time;
	InvalidTimeException(const string& str) : input_time(str)
	{
	}
};

// hh:mm:ss �������� �����
ostream& operator<<(ostream& os, const WorldClock& c);

// hh:mm:ss �� �Է¹���.
// ����� �Է� ������ >> operator�� InvalidTimeException�� �߻��� �� ����.
istream& operator>>(istream& is, WorldClock& c);
