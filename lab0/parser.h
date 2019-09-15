class Parser{
private:

	int Count = 0;
	std::map<std::string, int> Container; 
	std::vector<std::pair<int, std::string>> Items;
	
public:
	std::string CurStr = {};
	
	Parser(){
		int Count = 0;
		std::map<std::string, int> Container; 
		std::vector<std::pair<int, std::string>> Items;
	}
	
	void MapSort(){
		for (auto it = Parser::Container.begin(); it != Parser::Container.end(); it++)
			Items.push_back(make_pair(it->second, it->first));
		
		std::sort(Items.begin(), Items.end(), std::greater<>());
		
	}
	
	void Recount(){
		Count++;
		if(Container.count(CurStr))
			Container[CurStr]++;
		else
			if(isalpha(CurStr[0]) || isdigit(CurStr[0]))
				Container.insert(make_pair(CurStr, 1));
		CurStr = {};
	}
	
	void Output(std::ofstream &out){
		MapSort();
 
		for (auto i = Items.begin(); i!= Items.end(); ++i)
			out << i->second << ';' << i->first << ';' << (double)i->first / Count * 100 << "%;\n";
	}

};
