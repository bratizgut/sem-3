class Parser{
private:

	int Count = 0;
	std::map<std::string, int> Container; 
	std::vector<std::pair<std::string, int>> Items;
		
	struct sort_pred {
		bool operator()(const std::pair<std::string,int> &left, const std::pair<std::string,int> &right) {
			return left.second > right.second;
    }
	
};
	
public:
	std::string CurStr = {};
	
	Parser(){
		int Count = 0;
		std::map<std::string, int> Container; 
		std::vector<std::pair<std::string, int>> Items;
	}
	
	void MapSort(){
		std::map<std::string, int>::iterator it;
		
		for (it = Parser::Container.begin(); it != Parser::Container.end(); it++)
			Items.push_back(make_pair(it->first, it->second));
		
		std::sort(Items.begin(), Items.end(), sort_pred());
		
	}
	
	void Recount(){
		Parser::Count++;
		if(Parser::Container.count(CurStr))
			Parser::Container[CurStr]++;
		else
			if(isalpha(CurStr[0]) || isdigit(CurStr[0]))
				Parser::Container.insert(make_pair(CurStr, 1));
		CurStr = {};
	}
	
	void Output(std::ofstream &out){
		MapSort();
 
		for (auto i = Items.begin(); i!= Items.end(); ++i)
			out << i->first << ';' << i->second << ';' << (double)i->second / Count * 100 << "%;\n";
	}
};