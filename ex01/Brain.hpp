#pragma once

#include <iostream>
#include <string>

#define MAX_IDEAS 100

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);

		const std::string& getIdea(size_t index) const;
		const std::string* getIdeaAddress(size_t index) const;

		void setIdea(size_t index, const std::string &idea);

	private:
		std::string ideas[MAX_IDEAS];
};