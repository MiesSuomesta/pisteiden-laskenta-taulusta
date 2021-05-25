
#ifndef VECTOR_H
#define VECTOR_H 1

class Vector{
	public:
		/* Constructor */
		Vector(int s): elem{new double[s]},sz{s} {}

		// Operaattori []
		double& operator[](int i) { return elem[i]; }

		int size() const { return sz; }

	private:
		int sz;
		double *elem;
	
};



#endif /* VECTOR_H */
