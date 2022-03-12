#include <iostream>
#include <cctype>
#include <string>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
using namespace std;

void delete_by_number();
void delete_by_num_output();
void delete_by_name();
int main();
int file_length();
bool isEmpty();

struct agency
{
	string type;
	int cont, cont1;
	int difficulty;
	char name[20];
	int open_day, open_month, open_year;
	int duration;
	int date_close, close_month, close_year;
	float price_day;
	float price_all;
} agency_arr[5];


agency mystruct;
agency mystruct2;
FILE* f;
errno_t err;
const string file_name = "info";

int File_isn_pust()
{
	if ((err = fopen_s(&f, file_name.c_str(), "rb")) != 0)
	{
		return 1;
	}
	else if (fread(&mystruct, sizeof(agency), 1, f) == 0)
	{
		fclose(f);
		return 2;
	}
	else
	{
		fclose(f);
		return 3;
	}
}

void input()
{
	system("cls");

	err = fopen_s(&f, file_name.c_str(), "ab+");

	int five = 0;

	five++;
	int answer, difficulty;
type:
	cout << "Оберіть тип справи\n 1 - вбивство,\n 2 - грабіж,\n 3 - пошук \n\n 0 - повернутись у головне меню(запис буде втрачено)" << endl;
	cin >> answer;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');

		system("cls");

		cout << "Оберіть із запропонованих варіантів" << endl << endl;
		goto type;
	}
	else
	{
		cin.ignore(32767, '\n');
	}

	system("cls");

	if (answer < 0 || answer > 3)
	{
		cout << "Введіть число від 0 до 3" << endl << endl;
		goto type;
	}

	switch (answer)
	{
	case 1:
		mystruct.type = "вбивство";
		break;
	case 2:
		mystruct.type = "грабіж";
		break;
	case 3:
		mystruct.type = "пошук";
		break;
	case 0:
		return;
	}

difficulty:

	cout << "Введіть складність справи\n 1 - (1 - 2 ступінь),\n 2 - (3 ступінь) \n\n 0 - повернутись у головне меню(запис буде втрачено)" << endl;

	cin >> difficulty;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");
		cout << "Оберіть із запропонованих варіантів" << endl << endl;
		goto difficulty;
	}
	else
	{
		cin.ignore(32767, '\n');
	}

	if (!(difficulty >= 1 && difficulty <= 2))
	{
		goto difficulty;
	}

	system("cls");

	cout << "Введіть ім'я замовника(прізвище та ініціали): ";

	string name = "";

	cin.clear();
	getline(cin, name);

	strcpy_s(mystruct.name, name.substr(0, 19).c_str());

	system("cls");

err:
	cout << "Введіть дату відкриття справи: " << endl;

	cout << "Введіть день: " << endl;
	cin >> mystruct.open_day;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");
		cout << "Введіть число" << endl << endl;
		goto err;
	}
	else
	{
		cin.ignore(32767, '\n');
	}

	if (mystruct.open_day > 31 || mystruct.open_day < 1)
	{
		system("cls");
		cout << "Такої дати не існує" << endl << endl;
		goto err;
	}
	system("cls");

e:
	cout << "Введіть місяць: " << endl;
	cin >> mystruct.open_month;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");

		cout << "Введіть день" << endl << endl;
		goto e;
	}
	else
	{
		cin.ignore(32767, '\n');
	}

	if (mystruct.open_month > 12 || mystruct.open_month < 1)
	{
		system("cls");

		cout << "Такої дати не існує" << endl << endl;
		goto e;
	}
	system("cls");
y:
	cout << "Введіть рік (від 2000): " << endl;
	cin >> mystruct.open_year;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');

		system("cls");

		cout << "Введіть число" << endl << endl;
		goto y;
	}
	else
	{
		cin.ignore(32767, '\n');
	}


	if (mystruct.open_year < 2000 || mystruct.open_year > 2022)
	{
		system("cls");
		cout << "Введіть допустимий рік" << endl << endl;
		goto y;
	}
	system("cls");

	if (mystruct.type == "вбивство")
	{
		if (difficulty == 1)
		{
			to_string(difficulty) =
				mystruct.duration = 45;

			mystruct.price_day = 1000;
		}

		if (difficulty == 2)
		{
			mystruct.duration = 30;

			mystruct.price_day = 700;
		}
	}

	if (mystruct.type == "грабіж")
	{
		if (difficulty == 1)
		{
			mystruct.duration = 7;

			mystruct.price_day = 600;
		}

		if (difficulty == 2)
		{
			mystruct.duration = 5;

			mystruct.price_day = 500;

		}
	}

	if (mystruct.type == "пошук")
	{
		if (difficulty == 1)
		{
			mystruct.duration = 20;

			mystruct.price_day = 500;
		}

		if (difficulty == 2)
		{
			mystruct.duration = 10;

			mystruct.price_day = 400;
		}
	}

	mystruct.date_close = mystruct.open_day + mystruct.duration;
	mystruct.close_month = mystruct.open_month;
	mystruct.close_year = mystruct.open_year;

	if (mystruct.date_close > 31)
	{
		mystruct.close_month += mystruct.date_close / 31;
		mystruct.date_close = mystruct.date_close % 31;
	}

	if (mystruct.close_month > 12)
	{
		mystruct.close_year += mystruct.close_month / 12;
		mystruct.close_month = mystruct.close_month % 12;
	}
	mystruct.price_all = mystruct.duration * mystruct.price_day;

	mystruct.difficulty = difficulty;

question:
	int question = 0;
	cout << "Додати запис до файлу? \n1 - Так \n2 - Ні(запис буде втрачено)" << endl << endl;
	try
	{
		cin >> question;
	}
	catch (const std::exception&)
	{
		cout << "Оберіть з запропонованих варінтів";
		goto question;
	}

	if (!(question == 1 || question == 2))
	{
		cout << "Оберіть з запропонованих варінтів";
		goto question;
	}

	if (question == 1)
	{
		fwrite(&mystruct, sizeof(agency), 1, f);
	}
	else if (question == 2)
	{
		return;
	}

	fclose(f);

	system("cls");

}

void vertical()
{
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << "\xBA";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void table_start()
{
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << endl << left << "\xC9\xCD\xCD\xCD\xCD\xCD" <<
		setfill('\xCD') << setw(16) << "\xCB" <<
		setfill('\xCD') << setw(21) << "\xCB" <<
		setfill('\xCD') << setw(21) << "\xCB" <<
		setfill('\xCD') << setw(26) << "\xCB" <<
		setfill('\xCD') << setw(21) << "\xCB" <<
		setfill('\xCD') << setw(26) << "\xCB" <<
		setfill('\xCD') << setw(21) << "\xCB" <<
		setfill('\xCD') << setw(21) << "\xCB" << "\xBB" << endl;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vertical();
	cout << setfill(' ') << left << setw(5) << "№";
	vertical();
	cout << left << setw(15) << "Тип";
	vertical();
	cout << left << setw(20) << "Складність";
	vertical();
	cout << left << setw(20) << "ПІБ";
	vertical();
	cout << left << setw(25) << "Дата відкриття";
	vertical();
	cout << left << setw(20) << "План тривалості";
	vertical();
	cout << left << setw(25) << "Планова дата закриття";
	vertical();
	cout << left << setw(20) << "Вартість за день";
	vertical();
	cout << left << setw(20) << "Повна вартість";
	vertical();
}


void table_end()
{
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << endl << left << "\xC8\xCD\xCD\xCD\xCD\xCD" <<
		setfill('\xCD') << setw(16) << "\xCA" <<
		setfill('\xCD') << setw(21) << "\xCA" <<
		setfill('\xCD') << setw(21) << "\xCA" <<
		setfill('\xCD') << setw(26) << "\xCA" <<
		setfill('\xCD') << setw(21) << "\xCA" <<
		setfill('\xCD') << setw(26) << "\xCA" <<
		setfill('\xCD') << setw(21) << "\xCA" <<
		setfill('\xCD') << setw(21) << "\xCA" << "\xBC" << endl;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void table_output()
{
	err = fopen_s(&f, file_name.c_str(), "rb");
	int num = 1;
	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		cout << endl << left << "\xCC\xCD\xCD\xCD\xCD\xCD" <<
			setfill('\xCD') << setw(16) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" <<
			setfill('\xCD') << setw(26) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" <<
			setfill('\xCD') << setw(26) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" << "\xB9";
		cout << endl;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		vertical();
		cout
			<< left
			<< std::setfill(' ')
			<< setw(5)
			<< num++;
		vertical();
		cout
			<< left
			<< setw(15)
			<< mystruct.type;

		vertical();

		if (mystruct.difficulty == 1)
		{

			cout
				<< left
				<< setw(20)
				<< "1 - 2 ступінь";
			vertical();
		}
		else
		{
			cout
				<< left
				<< setw(20)
				<< "3 ступінь";
			vertical();
		}
		cout
			<< left
			<< setw(20)
			<< mystruct.name;
		vertical();
		cout
			<< left
			<< setw(25);
		if (mystruct.open_month < 10)
		{
			cout << to_string(mystruct.open_day) + ".0" + to_string(mystruct.open_month) + "." + to_string(mystruct.open_year);
			vertical();
		}
		else
		{
			cout << to_string(mystruct.open_day) + "." + to_string(mystruct.open_month) + "." + to_string(mystruct.open_year);
			vertical();
		}
		cout
			<< left
			<< setw(20)
			<< mystruct.duration;
		vertical();
		cout
			<< left
			<< setw(25);
		if (mystruct.close_month < 10)
		{
			cout << to_string(mystruct.date_close) + ".0" + to_string(mystruct.close_month) + "." + to_string(mystruct.close_year);
			vertical();
		}
		else
		{
			cout << to_string(mystruct.date_close) + "." + to_string(mystruct.close_month) + "." + to_string(mystruct.close_year);
			vertical();
		}

		cout
			<< left
			<< setw(20)
			<< mystruct.price_day;
		vertical();
		cout
			<< left
			<< setw(20)
			<< mystruct.price_all;
		vertical();
	}
	num++;
	fclose(f);
}



void output()
{
	bool exist = false;
	int z;
	z = File_isn_pust();
	if (z == 1)
	{
		exist = true;
		system("cls");
		cout << "Файл не відкрито";
		cout << endl << endl << "Натисніть будь-яку клавішу. . .";
		_getch();
		system("cls");
		main();
		return;
	}
	if (z == 2)
	{
		exist = true;
		system("cls");
		cout << "Файл пустий";
		fclose(f);
		main();
		return;
	}
	table_start();
	table_output();
	table_end();


}

void notes_output()
{
	system("cls");
	output();
	cout << endl << "Натисніть будь-яку клавішу. . .";
	_getch();
}

void request_percent_table_start()
{
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	std::cout << std::endl << std::left << "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD" <<
		std::setfill('\xCD') << std::setw(26) << "\xCB" << "\xBB" << std::endl;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vertical();
	std::cout
		<< std::setfill(' ')
		<< std::left
		<< std::setw(20)
		<< "Тип справи";
	vertical();
	std::cout << std::left
		<< std::setw(25)
		<< "Відсоткове співвідношення";
	vertical();
	std::cout << std::endl;
}

void request_percent_table_end()
{
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	std::cout << std::left << "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD" <<
		std::setfill('\xCD') << std::setw(26) << "\xCA" << "\xBC" << std::endl;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void requestByType()
{
	system("cls");

	int z;
	z = File_isn_pust();
	if (z == 1)
	{
		cout << "Файл не відкрито";
		_getch();
		return;
	}
	if (z == 2)
	{
		cout << "Файл пустий";
		fclose(f);
		_getch();
		return;
	}

	int answer, sum = 0;
	string task;

startReq1:

	cout << "Оберіть тип справи\n 1 - вбивство,\n 2 - грабіж,\n 3 - пошук\n 0 - повернутись у головне меню" << endl;
	cin >> answer;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");
		cout << "Введіть число" << endl << endl;
		goto startReq1;
	}
	else
	{
		cin.ignore(32767, '\n');
	}

	if (answer > 3 || answer < 0)
	{
		system("cls");
		cout << "Оберіть із запропонованих варіантів" << endl << endl;
		goto startReq1;
	}

	switch (answer)
	{
	case 1:
		task = "вбивство";
		break;
	case 2:
		task = "грабіж";
		break;
	case 3:
		task = "пошук";
		break;
	case 0:
		system("cls");
		return;
	}

	int num = 1;

	err = fopen_s(&f, file_name.c_str(), "rb");
	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		if (mystruct.type == task)
		{
			sum += mystruct.price_all;
		}
	}
	fclose(f);

	if (sum == 0)
	{
		system("cls");
		cout << "Немає справ за обраним типом" << endl << endl;
		goto startReq1;
	}

	system("cls");

	cout << endl << endl << "Повна вартість за типом справи: " << sum << endl << endl;

	table_start();
	err = fopen_s(&f, file_name.c_str(), "rb");
	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		if (mystruct.type == task)
		{
			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			cout << endl << left << "\xCC\xCD\xCD\xCD\xCD\xCD" <<
				setfill('\xCD') << setw(16) << "\xCE" <<
				setfill('\xCD') << setw(21) << "\xCE" <<
				setfill('\xCD') << setw(21) << "\xCE" <<
				setfill('\xCD') << setw(26) << "\xCE" <<
				setfill('\xCD') << setw(21) << "\xCE" <<
				setfill('\xCD') << setw(26) << "\xCE" <<
				setfill('\xCD') << setw(21) << "\xCE" <<
				setfill('\xCD') << setw(21) << "\xCE" << "\xB9";
			cout << endl;
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			vertical();
			cout
				<< left
				<< std::setfill(' ')
				<< setw(5)
				<< num++;
			vertical();
			cout
				<< left
				<< setw(15)
				<< mystruct.type;
			vertical();

			if (mystruct.difficulty == 1)
			{

				cout
					<< left
					<< setw(20)
					<< "1 - 2 ступінь";
				vertical();
			}
			else
			{
				cout
					<< left
					<< setw(20)
					<< "3 ступінь";
				vertical();
			}
			cout
				<< left
				<< setw(20)
				<< mystruct.name;
			vertical();
			cout
				<< left
				<< setw(25);
			if (mystruct.open_month < 10)
			{
				cout << to_string(mystruct.open_day) + ".0" + to_string(mystruct.open_month) + "." + to_string(mystruct.open_year);
				vertical();
			}
			else
			{
				cout << to_string(mystruct.open_day) + "." + to_string(mystruct.open_month) + "." + to_string(mystruct.open_year);
				vertical();
			}
			cout
				<< left
				<< setw(20)
				<< mystruct.duration;
			vertical();
			cout
				<< left
				<< setw(25);
			if (mystruct.close_month < 10)
			{
				cout << to_string(mystruct.date_close) + ".0" + to_string(mystruct.close_month) + "." + to_string(mystruct.close_year);
				vertical();
			}
			else
			{
				cout << to_string(mystruct.date_close) + "." + to_string(mystruct.close_month) + "." + to_string(mystruct.close_year);
				vertical();
			}

			cout
				<< left
				<< setw(20)
				<< mystruct.price_day;
			vertical();
			cout
				<< left
				<< setw(20)
				<< mystruct.price_all;
			vertical();

			num++;

		}
	}

	table_end();

	cout << endl << endl << "Натисніть будь-яку клавішу. . .";

	fclose(f);
	_getch();
}

void requestByPercent()
{
	system("cls");

	float sum = 0, sum1 = 0, sum2 = 0, sum3 = 0;

	err = fopen_s(&f, file_name.c_str(), "rb");
	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{


		if (strcmp(mystruct.type.c_str(), "вбивство") == 0)
		{
			sum1++;
		}
		else if (strcmp(mystruct.type.c_str(), "грабіж") == 0)
		{
			sum2++;
		}
		else if (strcmp(mystruct.type.c_str(), "пошук") == 0)
		{
			sum3++;
		}
		sum++;
	}

	fclose(f);

	float quality1 = sum1 == 0 ? 0 : sum1 / sum * 100;
	float quality2 = sum2 == 0 ? 0 : sum2 / sum * 100;
	float quality3 = sum3 == 0 ? 0 : sum3 / sum * 100;

	string per1 = to_string(quality1).substr(0, 4);
	string per2 = to_string(quality2).substr(0, 4);
	string per3 = to_string(quality3).substr(0, 4);

	request_percent_table_start();

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	std::cout << std::left << "\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD" <<
		std::setfill('\xCD') << std::setw(26) << "\xCE" << "\xB9" << std::endl;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vertical();
	std::cout
		<< std::setfill(' ')
		<< std::left
		<< std::setw(20)
		<< "вбивство";
	vertical();
	std::cout << std::left
		<< std::setw(25)
		<< per1 + " % ";
	vertical();
	std::cout << std::endl;

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	std::cout << std::left << "\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD" <<
		std::setfill('\xCD') << std::setw(26) << "\xCE" << "\xB9" << std::endl;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vertical();
	std::cout
		<< std::setfill(' ')
		<< std::left
		<< std::setw(20)
		<< "грабіж";
	vertical();
	std::cout << std::left
		<< std::setw(25)
		<< per2 + " % ";
	vertical();
	std::cout << std::endl;

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	std::cout << std::left << "\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD" <<
		std::setfill('\xCD') << std::setw(26) << "\xCE" << "\xB9" << std::endl;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vertical();
	std::cout
		<< std::setfill(' ')
		<< std::left
		<< std::setw(20)
		<< "розшук";
	vertical();
	std::cout << std::left
		<< std::setw(25)
		<< per3 + " % ";
	vertical();
	std::cout << std::endl;

	request_percent_table_end();

	cout << endl << endl << "Натисніть будь-яку клавішу. . .";

	_getch();

}

void request3()
{
	int len = file_length();

	int get = 0;

	system("cls");

p:
	int answer;

	cout << "Оберіть тип справи\n 1 - вбивство,\n 2 - грабіж,\n 3 - пошук \n 4 - вихід у головне меню" << endl;

	cin >> answer;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");
		cout << "Оберіть із запропонованих варіантів" << endl << endl;

		goto p;
	}
	else
	{
		cin.ignore(32767, '\n');
	}

	if (answer < 1 || answer > 4)
	{
		system("cls");

		cout << "Введіть число від 1 до 4" << endl;
		goto p;
	}
	string type = "";
	switch (answer)
	{
	case 1:
		type = "вбивство";
		break;
	case 2:
		type = "грабіж";
		break;
	case 3:
		type = "пошук";
		break;
	case 4:
		system("cls");
		return;
	}

	bool exist = false;
	err = fopen_s(&f, file_name.c_str(), "rb");
	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		if (strcmp(mystruct.type.c_str(), type.c_str()) != 0)
		{
			continue;
		}
		exist = true;
	}

	fclose(f);
	if (!exist)
	{
		cout << "Справ за таким типом немає" << endl << endl << "Натисніть будь_яку клавішу. . .";
		_getch();
		system("cls");

		goto p;
		return;
	}
	system("cls");

	cout << "найскладніші справи за типом " << type << ":" << endl << endl;


	table_start();

	err = fopen_s(&f, file_name.c_str(), "rb");
	int num = 1;
	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		if (!(strcmp(mystruct.type.c_str(), type.c_str()) == 0 && mystruct.difficulty == 1))
		{
			continue;
		}

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		cout << endl << left << "\xCC\xCD\xCD\xCD\xCD\xCD" <<
			setfill('\xCD') << setw(16) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" <<
			setfill('\xCD') << setw(26) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" <<
			setfill('\xCD') << setw(26) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" <<
			setfill('\xCD') << setw(21) << "\xCE" << "\xB9";
		cout << endl;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		vertical();
		cout
			<< left
			<< std::setfill(' ')
			<< setw(5)
			<< num++;
		vertical();
		cout
			<< left
			<< setw(15)
			<< mystruct.type;
		vertical();

		if (mystruct.difficulty == 1)
		{

			cout
				<< left
				<< setw(20)
				<< "1 - 2 ступінь";
			vertical();
		}
		else
		{
			cout
				<< left
				<< setw(20)
				<< "3 ступінь";
			vertical();
		}
		cout
			<< left
			<< setw(20)
			<< mystruct.name;
		vertical();
		cout
			<< left
			<< setw(25);
		if (mystruct.open_month < 10)
		{
			cout << to_string(mystruct.open_day) + ".0" + to_string(mystruct.open_month) + "." + to_string(mystruct.open_year);
			vertical();
		}
		else
		{
			cout << to_string(mystruct.open_day) + "." + to_string(mystruct.open_month) + "." + to_string(mystruct.open_year);
			vertical();
		}
		cout
			<< left
			<< setw(20)
			<< mystruct.duration;
		vertical();
		cout
			<< left
			<< setw(25);
		if (mystruct.close_month < 10)
		{
			cout << to_string(mystruct.date_close) + ".0" + to_string(mystruct.close_month) + "." + to_string(mystruct.close_year);
			vertical();
		}
		else
		{
			cout << to_string(mystruct.date_close) + "." + to_string(mystruct.close_month) + "." + to_string(mystruct.close_year);
			vertical();
		}

		cout
			<< left
			<< setw(20)
			<< mystruct.price_day;
		vertical();
		cout
			<< left
			<< setw(20)
			<< mystruct.price_all;
		vertical();

	}
	table_end();


	num++;
	fclose(f);
	system("pause>0");
}

bool check_name(string name1)
{
	FILE* contic;
	err = fopen_s(&contic, (file_name + "_temp").c_str(), "rb");

	while (fread(&mystruct2, sizeof(agency), 1, contic) == 1)
	{
		if (strcmp(mystruct2.name, name1.c_str()) == 0)
		{
			fclose(contic);
			return false;
		}
	}
	fclose(contic);
	return true;
}

void req_4()
{
	system("cls");

	isEmpty();

	FILE* contic;
	FILE* contic_t;

	FILE* f0;
	err = fopen_s(&f, file_name.c_str(), "rb");
	err = fopen_s(&f0, (file_name + "_copy").c_str(), "ab+");

	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		fwrite(&mystruct, sizeof(agency), 1, f0);
	}
	fclose(f);
	fclose(f0);

	FILE* temp;
	err = fopen_s(&f, file_name.c_str(), "rb");

	string name = "";
	string cont_out = "";

	err = fopen_s(&contic, (file_name + "_temp").c_str(), "ab+");
	fclose(contic);

	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		int nameCount = 1;

		name = mystruct.name;

		int count = 0;

		err = fopen_s(&f0, (file_name + "_copy").c_str(), "rb");
		while (fread(&mystruct2, sizeof(agency), 1, f0) == 1)
		{
			count++;

			if (mystruct2.name == name)
			{
				nameCount++;

			}

		}
		fclose(f0);

		//cont_out = mystruct.name;
		mystruct.cont = nameCount;
		bool exist = check_name(mystruct.name);
		if (exist)
		{
			err = fopen_s(&contic, (file_name + "_temp").c_str(), "ab+");
			fwrite(&mystruct, sizeof(agency), 1, contic);
			fclose(contic);
		}
	}
	fclose(f);

	string name1 = "";

	int max = 0;

	int number = 0;

	err = fopen_s(&temp, (file_name + "_temp").c_str(), "rb");
	while (fread(&mystruct, sizeof(agency), 1, temp) == 1)
	{
		if (number == 0)
		{
			max = mystruct.cont;
		}

		number++;

		if (mystruct.cont > max)
		{
			max = mystruct.cont;
		}
		else
		{
			continue;
		}
	}
	fclose(temp);

	name = mystruct.name;

	cout << "Найактивнішi замовники: " << endl;

	err = fopen_s(&contic, (file_name + "_temp").c_str(), "rb");
	while (fread(&mystruct, sizeof(agency), 1, contic) == 1)
	{
		if (mystruct.cont == max)
		{
			cout << mystruct.name << endl;
		}

	}
	fclose(contic);
	remove((file_name + "_temp").c_str());
	remove((file_name + "_copy").c_str());


	_getch();
}

bool check_date(int date_d, int date_m, int date_y)
{
	FILE* contic;
	err = fopen_s(&contic, (file_name + "_temp").c_str(), "rb");

	while (fread(&mystruct2, sizeof(agency), 1, contic) == 1)
	{
		if (mystruct2.open_day == date_d && mystruct2.open_month == date_m && mystruct2.open_year == date_y)
		{
			fclose(contic);
			return false;
		}
	}
	fclose(contic);
	return true;
}

void req_5()
{
	system("cls");

	isEmpty();

	FILE* contic;

	FILE* f0;
	err = fopen_s(&f, file_name.c_str(), "rb");
	err = fopen_s(&f0, (file_name + "_copy").c_str(), "ab+");

	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		fwrite(&mystruct, sizeof(agency), 1, f0);
	}
	fclose(f);
	fclose(f0);

	FILE* temp;
	err = fopen_s(&f, file_name.c_str(), "rb");

	string cont_out = "";

	err = fopen_s(&contic, (file_name + "_temp").c_str(), "ab+");
	fclose(contic);

	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		int dateCount = 1;

		int op_day = mystruct.open_day;
		int op_mon = mystruct.open_month;
		int op_year = mystruct.open_year;

		int count = 0;

		err = fopen_s(&f0, (file_name + "_copy").c_str(), "rb");
		while (fread(&mystruct2, sizeof(agency), 1, f0) == 1)
		{
			count++;

			if (mystruct2.open_year == op_year && mystruct2.open_month == op_mon && mystruct2.open_day == op_day)
			{
				dateCount++;
			}
		}
		fclose(f0);

		mystruct.cont = dateCount;
		bool exist = check_date(mystruct.open_day, mystruct.open_month, mystruct.open_year);
		if (exist)
		{
			err = fopen_s(&contic, (file_name + "_temp").c_str(), "ab+");
			fwrite(&mystruct, sizeof(agency), 1, contic);
			fclose(contic);
		}
	}
	fclose(f);

	int date_d, date_m, date_y;

	int max = 0;

	int number = 0;

	err = fopen_s(&temp, (file_name + "_temp").c_str(), "rb");
	while (fread(&mystruct, sizeof(agency), 1, temp) == 1)
	{
		if (number == 0)
		{
			max = mystruct.cont;
		}

		number++;

		if (mystruct.cont > max)
		{
			max = mystruct.cont;
		}
		else
		{
			continue;
		}
	}
	fclose(temp);

	cout << "days: " << endl;

	err = fopen_s(&contic, (file_name + "_temp").c_str(), "rb");
	while (fread(&mystruct, sizeof(agency), 1, contic) == 1)
	{
		if (mystruct.cont == max)
		{
			cout << to_string(mystruct.open_day) + "." + to_string(mystruct.open_month) + "." + to_string(mystruct.open_year) << endl;
		}

	}
	fclose(contic);
	remove((file_name + "_temp").c_str());
	remove((file_name + "_copy").c_str());


	_getch();
}


void requestOutput()
{
	bool exist = isEmpty();

	if (exist)
	{
		return;
	}

	while (true)
	{

		system("cls");

	requestOutput:

		int requestQue;

		cout << "Оберіть запит: \n1 - загальна вартість розслідування справ обраного типу \n2 - відсоткове співвідношення справ за усіма типами \n3 - перелік найскладніших справ обраного типу \n4 - найактивніші замовники \n5 - дні, коли справ було відкрито найбільше \n\n0 - повернутись у головне меню" << endl;

		cin >> requestQue;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Оберіть із запропонованих варіантів" << endl << endl;
			goto requestOutput;
		}
		else
		{
			cin.ignore(32767, '\n');
		}

		if (requestQue >= 0 && requestQue < 6)
		{
			switch (requestQue)
			{
			case 1:
				requestByType();
				break;
			case 2:
				requestByPercent();
				break;
			case 3:
				request3();
				break;
			case 4:
				req_4();
				break;
			case 5:
				req_5();
				break;
			case 0:
				return;
			}
		}
		else
		{
			cout << "Оберіть із запропонованих варіантів" << endl << endl;
			goto requestOutput;
		}
	}
}

bool isEmpty()
{
	int z;
	z = File_isn_pust();
	if (z == 1)
	{
		system("cls");
		cout << "Файл не відкрито(натисніть будь-яку клавішу)" << endl;
		_getch();
		system("cls");
		return true;
	}
	if (z == 2)
	{
		system("cls");
		cout << endl << "Файл пустий(натисніть будь-яку клавішу)" << endl;
		fclose(f);
		_getch();
		system("cls");
		return true;
	}

	if (z != 1 && z != 2)
	{
		return false;
	}
}

int file_length()
{
	int length = 0;

	bool exist = isEmpty();

	if (exist)
	{
		main();
	}

	err = fopen_s(&f, file_name.c_str(), "rb");
	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		length++;
	}

	fclose(f);
	return length;
}



void file_delete()
{
	system("cls");

	bool exist = isEmpty();
	if (exist)
	{
		system("cls");

		return;
		
	}

startFileDelete:


	int taskin;

	cout << "Оберіть варіант видалення даних:\n1 - За номером\n2 - За ПІБ\n0 - Повернутися у головне меню" << endl;
	cin >> taskin;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Оберіть із запропонованих варіантів" << endl << endl;
		goto startFileDelete;
	}
	else
	{
		cin.ignore(32767, '\n');
	}


	if (taskin < 0 || taskin > 2)
	{
		system("cls");
		cout << "Оберіть із запропонованих варіантів" << endl << endl;
		goto startFileDelete;
	}

	switch (taskin)
	{
	case 0:
		return;
		break;
	case 1:
		delete_by_num_output();
		break;
	case 2:
		delete_by_name();
		break;

	}
}

void delete_(int number)
{
	system("cls");

	FILE* f2;
	err = fopen_s(&f, file_name.c_str(), "rb");
	err = fopen_s(&f2, (file_name + "_copy").c_str(), "ab+");

	int i = 0;

	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		i++;

		if (i == number)
		{
			continue;
		}


		fwrite(&mystruct, sizeof(agency), 1, f2);
	}

	fclose(f);
	fclose(f2);
	remove(file_name.c_str());
	rename((file_name + "_copy").c_str(), file_name.c_str());
}

void delete_by_num_output()
{
	output();
	delete_by_number();
}

void delete_by_number()
{
	string numberCheck;
	int fileDelAns;
	int number = 0;
	int length = file_length();
l:
	//output();

	cout << "Уведіть номер, за яким хочете видалити: ";

	cin >> number;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		system("cls");
		cout << "Оберіть із запропонованих варіантів" << endl << endl;
		goto l;
	}
	else
	{
		cin.ignore(32767, '\n');
	}

	if (number > length)
	{
		system("cls");
		cout << "Оберіть із існуючих варіантів" << endl << endl;
		goto l;
	}
w:
	if (number > 0 && number <= length)
	{
		cout << "Ви впевнені що хочете видалити запис під номером " << number << "?\n1 - Так \n2 - Обрати інший номер \n0 - Вихід у головне меню" << endl;

		cin >> fileDelAns;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Оберіть із запропонованих варіантів" << endl << endl;
			goto w;
		}
		else
		{
			cin.ignore(32767, '\n');
		}

		if (fileDelAns < 0 || fileDelAns > 3)
		{
			cout << "Введіть 0, 1 або 2" << endl;
			goto l;
		}
		else
		{
			switch (fileDelAns)
			{
			case 1:
				delete_(number);
				break;
			case 2:
				goto l;
				break;
			case 0:
				return;
			}
		}
	}
	else
	{
		cout << "Такого запису не існує" << endl;
		system("cls");
		goto l;
	}
}

void delete_name_checksa(int number)
{
	FILE* f2;

	int i = 0;

	err = fopen_s(&f, file_name.c_str(), "rb");
	err = fopen_s(&f2, (file_name + "_copy").c_str(), "ab+");

	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		if (number == mystruct.cont)
		{
			continue;
		}

		fwrite(&mystruct, sizeof(agency), 1, f2);

	}

	fclose(f);
	fclose(f2);
	remove(file_name.c_str());
	rename((file_name + "_copy").c_str(), file_name.c_str());
}

void delete_by_name()
{
startDelName:

	FILE* f2;

	FILE* f0;

	int fileDelAns;
	string delName;
	int checksa = 0, c = 0;
	int length = file_length();

	output();

	cout << "Введіть ПІБ, за яким хочете видалити запис: ";

	getline(cin, delName);

	err = fopen_s(&f, file_name.c_str(), "rb");

	int i = 0;

	while (fread(&mystruct, sizeof(agency), 1, f) == 1)
	{
		if (string(mystruct.name).find(delName) != string::npos)
		{
			checksa++;
			continue;
		}

	}
	fclose(f);


	int num = 1;

	if (checksa == 1)
	{
		err = fopen_s(&f, file_name.c_str(), "rb");
		err = fopen_s(&f2, (file_name + "_copy").c_str(), "ab+");
		while (fread(&mystruct, sizeof(agency), 1, f) == 1)
		{
			if (string(mystruct.name).find(delName) != string::npos)
			{
				continue;
			}

			fwrite(&mystruct, sizeof(agency), 1, f2);

		}
		fclose(f2);
		fclose(f);

		remove(file_name.c_str());
		rename((file_name + "_copy").c_str(), file_name.c_str());
	}

	int cont = 1;
	mystruct.cont = 0;


	if (checksa == 0)
	{
		system("cls");
		cout << "Такого запису не існує" << endl << endl;
		goto startDelName;
	}
	else
	{
		if (checksa > 1)
		{
			system("cls");
			cout << "Існує декілька записів з таким ПІБ" << endl << "Оберіть номер запису, який хочете видалити" << endl << endl;
		l:
			table_start();

			
			err = fopen_s(&f, (file_name).c_str(), "rb");
			while (fread(&mystruct, sizeof(agency), 1, f) == 1)
			{
				if (string(mystruct.name).find(delName) != string::npos)
				{
					SetConsoleCP(866);
					SetConsoleOutputCP(866);
					cout << endl << left << "\xCC\xCD\xCD\xCD\xCD\xCD" <<
						setfill('\xCD') << setw(16) << "\xCE" <<
						setfill('\xCD') << setw(21) << "\xCE" <<
						setfill('\xCD') << setw(21) << "\xCE" <<
						setfill('\xCD') << setw(26) << "\xCE" <<
						setfill('\xCD') << setw(21) << "\xCE" <<
						setfill('\xCD') << setw(26) << "\xCE" <<
						setfill('\xCD') << setw(21) << "\xCE" <<
						setfill('\xCD') << setw(21) << "\xCE" << "\xB9";
					cout << endl;
					SetConsoleCP(1251);
					SetConsoleOutputCP(1251);

					vertical();
					cout
						<< left
						<< std::setfill(' ')
						<< setw(5)
						<< cont++;
					vertical();
					cout
						<< left
						<< setw(15)
						<< mystruct.type;

					vertical();

					if (mystruct.difficulty == 1)
					{
						cout
							<< left
							<< setw(20)
							<< "1 - 2 ступінь";
						vertical();
					}
					else
					{
						cout
							<< left
							<< setw(20)
							<< "3 ступінь";
						vertical();
					}
					cout
						<< left
						<< setw(20)
						<< mystruct.name;
					vertical();
					cout
						<< left
						<< setw(25);
					if (mystruct.open_month < 10)
					{
						cout << to_string(mystruct.open_day) + ".0" + to_string(mystruct.open_month) + "." + to_string(mystruct.open_year);
						vertical();
					}
					else
					{
						cout << to_string(mystruct.open_day) + "." + to_string(mystruct.open_month) + "." + to_string(mystruct.open_year);
						vertical();
					}
					cout
						<< left
						<< setw(20)
						<< mystruct.duration;
					vertical();
					cout
						<< left
						<< setw(25);
					if (mystruct.close_month < 10)
					{
						cout << to_string(mystruct.date_close) + ".0" + to_string(mystruct.close_month) + "." + to_string(mystruct.close_year);
						vertical();
					}
					else
					{
						cout << to_string(mystruct.date_close) + "." + to_string(mystruct.close_month) + "." + to_string(mystruct.close_year);
						vertical();
					}

					cout
						<< left
						<< setw(20)
						<< mystruct.price_day;
					vertical();
					cout
						<< left
						<< setw(20)
						<< mystruct.price_all;
					vertical();
				}
			}
			fclose(f);

			table_end();

			int number;
		//l:
			cout << "Уведіть номер, за яким хочете видалити: ";

			cin >> number;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				system("cls");
				cout << "Оберіть із запропонованих варіантів" << endl << endl;
				goto l;
			}
			else
			{
				cin.ignore(32767, '\n');
			}

			if (number > checksa)
			{
				system("cls");
				cout << "Оберіть із існуючих варіантів" << endl << endl;
				i = 0, cont = 1;
				goto l;
			}
		w:
			if (number > 0 && number <= checksa)
			{
				cout << "Ви впевнені що хочете видалити запис під номером " << number << "?\n1 - Так \n2 - Обрати інший номер \n0 - Вихід у головне меню" << endl;

				cin >> fileDelAns;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Оберіть із запропонованих варіантів" << endl << endl;
					goto w;
				}
				else
				{
					cin.ignore(32767, '\n');
				}

				int i = 0;

				if (fileDelAns < 0 || fileDelAns > 3)
				{
					cout << "Введіть 0, 1 або 2" << endl;
					goto l;
				}
				else
				{
					switch (fileDelAns)
					{
					case 1:
						fclose(f);
						err = fopen_s(&f2, (file_name + "_copy").c_str(), "ab+");
						err = fopen_s(&f, (file_name).c_str(), "rb");
						while (fread(&mystruct, sizeof(agency), 1, f) == 1)
						{
							if (string(mystruct.name).find(delName) != string::npos)
							{
								i++;
								if (number == i)
								{
									continue;
								}
								fwrite(&mystruct, sizeof(agency), 1, f2);
								continue;
							}
							fwrite(&mystruct, sizeof(agency), 1, f2);
						}
						fclose(f);
						fclose(f2);
						remove(file_name.c_str());
						rename((file_name + "_copy").c_str(), file_name.c_str());
						break;
					case 2:
						goto l;
						break;
					case 0:
						return;
					}
				}
			}

		}
		else
		{
			cout << "Ви впевнені що хочете видалити запис " << delName << " ?\n1 - Так \n2 - Обрати інший номер \n0 - Вихід у головне меню" << endl;
			cin >> fileDelAns;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Оберіть із запропонованих варіантів" << endl << endl;
				goto startDelName;
			}
			else
			{
				cin.ignore(32767, '\n');
			}

			if (fileDelAns < -1 || fileDelAns > 3)
			{
				cout << "Введіть 0, 1 або 2" << endl;
				goto startDelName;
			}
			if (fileDelAns == 2)
			{
				goto startDelName;
			}

			if (fileDelAns == 0)
			{
				return;
			}
		}

	}


}

void sortByName()
{
	FILE* f3;
	int length = file_length();
	err = fopen_s(&f3, (file_name + "_sort").c_str(), "ab+");

	agency min_item;

	for (int j = 0; j < length; j++)
	{
		int i = 0;
		int min_i = 1;
		err = fopen_s(&f, file_name.c_str(), "rb");
		while (fread(&mystruct, sizeof(agency), 1, f) == 1)
		{
			i++;
			if (i == 1)
			{
				min_item = mystruct;
				continue;
			}

			int compare = strcmp(min_item.name, mystruct.name);
			if (compare > 0)
			{
				min_item = mystruct;
				min_i = i;
			}

		}

		fwrite(&min_item, sizeof(agency), 1, f3);
		fclose(f);

		delete_(min_i);
	}

	fclose(f3);
	remove(file_name.c_str());
	rename((file_name + "_sort").c_str(), file_name.c_str());
}

void sortByDate()
{
	FILE* f3;
	int length = file_length();
	err = fopen_s(&f3, (file_name + "_sort").c_str(), "ab+");

	agency min_item;

	for (int j = 0; j < length; j++)
	{
		int i = 0;
		int min_i = 1;
		err = fopen_s(&f, file_name.c_str(), "rb");
		while (fread(&mystruct, sizeof(agency), 1, f) == 1)
		{
			i++;
			if (i == 1)
			{
				min_item = mystruct;
				continue;
			}

			if (mystruct.close_year < min_item.close_year)
			{
				min_item = mystruct;
				min_i = i;

			}
			else if (mystruct.close_year == min_item.close_year)
			{
				if (mystruct.close_month < min_item.close_month)
				{
					min_item = mystruct;
					min_i = i;
				}
				else if (mystruct.close_month == min_item.close_month)
				{
					if (mystruct.date_close < min_item.date_close)
					{
						min_item = mystruct;
						min_i = i;
					}
				}
			}
		}

		fwrite(&min_item, sizeof(agency), 1, f3);
		fclose(f);

		delete_(min_i);
	}

	fclose(f3);
	remove(file_name.c_str());
	rename((file_name + "_sort").c_str(), file_name.c_str());
}

void sortAll()
{

startSortAll:

	bool exist = isEmpty();

	if (exist)
	{
		return;
	}


	while (true)
	{
		system("cls");
		int sortAllque;
		cout << "Оберіть тип сортування: \n1 - За ПІБ \n2 - За планованою датою кінця розслідування \n\n0 - Повернутись у головне меню" << endl;

		cin >> sortAllque;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Оберіть із запропонованих варіантів" << endl << endl;
			goto startSortAll;
		}
		else
		{
			cin.ignore(32767, '\n');
		}

		if (sortAllque == 1 || sortAllque == 2 || sortAllque == 0)
		{
			switch (sortAllque)
			{
			case 1:
				sortByName();
				cout << "Сортування за ПІБ виконано" << endl << endl;
				output();

				cout << endl << endl << "Натисніть будь-яку клавішу. . .";
				_getch();

				break;
			case 2:
				sortByDate();
				cout << "Сортування за датою виконано" << endl << endl;
				output();

				cout << endl << endl << "Натисніть будь-яку клавішу. . .";
				_getch();

				break;
			case 0:
				return;
			}
		}
		else
		{
			cout << "Оберіть із запропонованих варіантів" << endl << endl;
			goto startSortAll;
		}
	}
}

int main()
{
mainCheck:
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int menushka;

	while (true)
	{
		cout << "Введіть:\n 1 - Додати записи\n 2 - Подивитись записи\n 3 - Виконати запит\n 4 - Відсортувати дані\n 5 - Видалити записи \n\n 0 - Вихід з програми" << endl;

		cin >> menushka;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Оберіть із запропонованих варіантів" << endl << endl;
			goto mainCheck;
		}
		else
		{
			cin.ignore(32767, '\n');
		}

		switch (menushka)
		{
		case 1:
			input();
			break;
		case 2:
			notes_output();
			break;
		case 3:
			requestOutput();
			break;
		case 4:
			sortAll();
			break;
		case 5:
			file_delete();
			break;
		case 0:
			return 0;
			break;
		}
		system("cls");
		//fhdushfkjsdfs
	}
}