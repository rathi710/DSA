class Solution {
public:
    int minNumberOfHours(int ie, int ig, vector<int>& energy, vector<int>& experience) 
    {
        int hours = 0;
        for (int i = 0; i < energy.size(); i++)
        {
            if (energy[i] >= ie)
            {
                hours += abs(energy[i] - ie) + 1;
                ie += abs(energy[i] - ie) + 1;
            }
            if (experience[i] >= ig)
            {
                hours += abs(experience[i] - ig) + 1;
                ig += abs(experience[i] - ig) + 1;
            }
			// At the end increase the experience by experience[i] and decrease the energy by                 //energy[i].
            ie -= energy[i];
            ig += experience[i];
        }
        return hours;
    }
};
