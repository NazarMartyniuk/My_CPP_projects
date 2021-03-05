#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <Windows.h>
using namespace std;
/*
	==============================
	 �������:
	==============================
	SecureBox ������� �� ������� ������� ��������.
	SecureBox ��������� ��������, ���� ��� �������� � ������� ����� false.
	SecureBox ����� ��������� �� ����������/���������� ����� ������ �������
	isLocked(). ���� SecureBox ������ - ������� isLocked ������ false.
	�������� �������� � ������� �� ����������� ����� �������� flip(x,y).
	��� ��������� ������ �������� � �������, ��������� ������� ���������� � �������� ��������.

	==============================
	 ������:
	==============================
	1. ����������� �������

	bool OpenBox(SecureBox& box)
	{
		// ....
		return box.isLocked();
	}

	������� ����� ������ ������������ ������������������ box.flip() c ���������� x,y ������� SecureBox.
	�������� ��� ������ SecureBox ���������.
	������� OpenBox ������ �������� ��� SecureBox ����� ����������� �� 100x100 ������������.

	2. ���������� ���� ��������� SecureBox � ������� ������������-���������� ����� � ����.
*/

class SecureBox
{
public:
	bool isLocked()
	{
		bool locked = false;
		for (uint32_t x = 0; x < m_xSize; x++) {
			for (uint32_t y = 0; y < m_ySize; y++) {
				locked = locked || m_LockSwitchers[x][y];
			}
		}
		return locked;
	}

	bool flip(uint32_t x, uint32_t y) //�� ��� ����� ����� flip ����� ���� �������� ��-������
	{
		if (x >= m_xSize || y >= m_ySize)
			return false;
		for (uint32_t tx = 0; tx < m_xSize; tx++)
			m_LockSwitchers[tx][y] = !m_LockSwitchers[tx][y];
		for (uint32_t ty = 0; ty < m_ySize; ty++)
			m_LockSwitchers[x][ty] = !m_LockSwitchers[x][ty];
		m_LockSwitchers[x][y] = !m_LockSwitchers[x][y];
		return true;
	}

	void lock()
	{
		const uint32_t minNumOfIters = 10;
		const uint32_t addNumOfIters = 1000;

		for (uint32_t iter = minNumOfIters + (rnd() % addNumOfIters); iter != 0; iter--)
			flip(rnd() & m_xSize, rnd() % m_ySize);
	}

	std::vector<std::vector<bool>> getState() {
		return m_LockSwitchers;
	}

	std::pair<uint32_t, uint32_t> getSize() {
		return std::make_pair(m_xSize, m_ySize);
	}

	SecureBox(uint32_t x, uint32_t y) : m_xSize(x), m_ySize(y), rnd(time(0))
	{
		m_LockSwitchers.resize(x);
		for (uint32_t i = 0; i < x; i++)
			m_LockSwitchers[i].resize(y);
		lock();
	}

private:
	std::mt19937_64 rnd;
	std::vector<std::vector<bool>> m_LockSwitchers;//������ ������� �� ��������� ����
	uint32_t m_xSize, m_ySize;
};

bool OpenBox(SecureBox& box)
{
	if (!box.isLocked())
		return 0;
	if ((box.getSize().first % 2) != 0 && (box.getSize().second % 2) != 0)
		if (box.getState()[box.getSize().first / 2][box.getSize().second / 2])
			box.flip(box.getSize().first / 2, box.getSize().second / 2);
	while (box.isLocked())
	{
		for (size_t i = 0; i < box.getSize().first; i++)
		{
			for (size_t j = 0; j < box.getSize().second; j++)
			{
				if (box.getState()[i][j])
				{
					if (i == 0)
						box.flip(i + 1, j);
					else
						box.flip(i - 1, j);
				}
			}
		}
	}
	return box.isLocked();
}