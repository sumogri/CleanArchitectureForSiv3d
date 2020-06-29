void Draw(){
	Scene::SetBackground(ColorF(1,1,1));
}

void Main()
{
	while (System::Update())
	{
		Scene::SetBackground(ColorF(0,0,0));
	}
}