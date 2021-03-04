using namespace std;
class HandleStack
{
public:
	int* mass;
	int size;
	HandleStack();
	HandleStack(int);
	HandleStack(const HandleStack& ref_Point);
	~HandleStack();
	void operator*(int scalar)
	{
		for (size_t i = 0; i < size; i++)
		{
			mass[i] *= scalar;
		}
	}
	int FindMax()
	{
		int temp = mass[0];
		for (size_t i = 0; i < size; i++)
		{
			if (mass[i] > temp)
			{
				temp = mass[i];
			}
		}
		return temp;
	}
	int FindMin()
	{
		int temp = mass[0];
		for (size_t i = 0; i < size; i++)
		{
			if (mass[i] < temp)
			{
				temp = mass[i];
			}
		}
		return temp;
	}
	double FindAvg()
	{
		double res = 0;
		for (size_t i = 0; i < size; i++)
		{
			res += mass[i];
		}
		res /= size;
		return res;
	}
	void StackClear()
	{
		delete[]mass;
		size = 0;
	}
	bool IsEmpty()
	{
		bool checker = true;
		if (size == 0)
		{
			return checker;
		}
		for (size_t i = 0; i < size; i++)
		{
			if (mass[i] != 0)
			{
				checker = false;
				break;
			}
		}
		return checker;
	}
	HandleStack& operator=(HandleStack& st1)
	{
		size = st1.size;
		delete mass;
		mass = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			mass[i] = st1.mass[i];
		}
		return *this;
	}
	void AddNew(int number)
	{
		int* tmp = new int[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			tmp[i] = mass[i];
		}
		size++;
		delete[]mass;
		mass = new int[size + 1];
		for (size_t i = 0; i < size - 1; i++)
		{
			mass[i] = tmp[i];
		}
		mass[size - 1] = number;
		delete[]tmp;
	}
	void DeleteLast()
	{
		int* tmp = new int[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			tmp[i] = mass[i];
		}
		size--;
		delete[]mass;
		mass = new int[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			mass[i] = tmp[i];
		}
		delete[]tmp;
	}
};