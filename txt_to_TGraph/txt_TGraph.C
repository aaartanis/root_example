//fill gdedx from a srim file. dedx[MeV/um,energy/u
bool readSrim(string fname, int mass, TGraph *gdedx)
{
	ifstream inf(fname);
	if (!inf.is_open())
	{
		cout << "Data File" << fname << "does not exist!" << endl;
		return 0
	}

	string ss, sunit;
	double a, b, e, ededx, ndedx;
	for (int j = 0; j < 24; j++)
	{
		getline(inf, ss);//�����ļ��п�ʼ��24���������ı���������
	}
	int i = 0;
	while (i < 10000)
	{
		inf >> e >> sunit >> ededx >> ndedx >> a >> ss >> a >> ss >> a >> ss;
		if (abs(e)) < 1.0e-4)
		{
			break;//���ڷ����ݣ�eֵΪ�㣬��ʱֹͣ������
		}
		if (sunit == "keV") e /= 1e3;
		if (sunit == "GeV") e *= 1e3;
		gdedx->Setpoint(i, e / mass, (ededx + ndedx) / 1000.);//x�ᵥλΪMeV/u,��ÿ���Ӷ�Ӧ������
	}



}