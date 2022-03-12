class Date
{
public:
	Date(int , int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();
	void displayDate();
private:
	int month;
	int day;
	int year;
};