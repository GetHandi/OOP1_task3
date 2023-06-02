
#include "Time.h"

void Time::fromSeconds(int Seconds)
{
	this->H = abs(Seconds) / 3600;
	this->M = (abs(Seconds) - 3600 * H) / 60;
	this->S = (abs(Seconds) - 3600 * H - 60 * M);

	if (Seconds < 0) { this->H *=(-1); this->M *= (-1); this->S *= (-1); }
}

Time::Time()
{
	H = M = S = 0;
}

Time::Time(int H, int M, int S)
{
	this->H = H;
	this->M = M;
	this->S = S;
}

void Time::SetTime(int H, int M, int S)
{
	this->H = H;
	this->M = M;
	this->S = S;
}

void Time::SetH(int H)
{
	this->H = H;
}

void Time::SetM(int M)
{
	this->M = M;
}

void Time::SetS(int S)
{
	this->S = S;
}

int Time::GetH()
{
	return H;
}

int Time::GetM()
{
	return M;
}

int Time::GetS()
{
	return S;
}

void Time::PrintTime()
{
	H < 0 || M < 0 || S < 0 ? cout << "Time: -" : cout << "Time: ";
	abs(H) < 10 ? cout << "0" << abs(H) : cout << abs(H);
	cout << ":";
	abs(M) < 10 ? cout << "0" << abs(M) : cout << abs(M);
	cout << ":";
	abs(S) < 10 ? cout << "0" << abs(S) : cout << abs(S);
}

void Time::SumTime(int H, int M, int S)
{
	this->H += H;
	this->M += M;
	this->S += S;
	fromSeconds(toSeconds());
}

void Time::DiffTime(int H, int M, int S)
{
	this->H -= H;
	this->M -= M;
	this->S -= S;
	fromSeconds(toSeconds());
}

void Time::AddH(int H)
{
	this->H += H;
	fromSeconds(toSeconds());
}

void Time::AddM(int M)
{
	this->M += M;
	fromSeconds(toSeconds());
}

void Time::AddS(int S)
{
	this->S += S;
	fromSeconds(toSeconds());
}

double Time::toHours()
{
	int Hours;
	if (this->H < 0 || this->M < 0 || this->S < 0) {
		return Hours = (-1) * (abs(double(this->H)) + abs(double(this->M)/60) + abs(double(this->S)/3600));
	}
	else {
		return Hours = double(this->H) + double(this->M) / 60 + double(this->S) / 3600;
	}
}

double Time::toMinutes()
{
	int Minutes;
	if (this->H < 0 || this->M < 0 || this->S < 0) {
		return Minutes = (-1) * (abs(double(this->H) * 60) + abs(double(this->M)) + abs(double(this->S) / 60));
	}
	else {
		return Minutes = double(this->H)*60 + double(this->M) + double(this->S) / 60;
	}
}


int Time::toSeconds()
{
	int Seconds;
	if (this->H < 0 || this->M < 0 || this->S < 0) {
		return Seconds = (-1) * (abs(this->H) * 3600 + abs(this->M) * 60 + abs(this->S));
	}
	else {
		return Seconds = this->H * 3600 + this->M * 60 + this->S;
	}
}

string Time::toString()
{
	return to_string(this->H) + ":" + to_string(this->M) + ":" + to_string(this->S);
}