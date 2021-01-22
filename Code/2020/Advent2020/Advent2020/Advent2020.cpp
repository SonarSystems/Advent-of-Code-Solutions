#include <iostream>
#include <string>
#include <sstream>

int main( )
{
	std::string passports[] = { "pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980 hcl:#623a2f", "eyr:2029 ecl:blu cid:129 byr:1989 iyr:2014 pid:896056539 hcl:#a97842 hgt:165cm", "hcl:#888785 hgt:164cm byr:2001 iyr:2015 cid:88 pid:545766238 ecl:hzl eyr:2022", "iyr:2010 hgt:158cm hcl:#b6652a ecl:blu byr:1944 eyr:2021 pid:093154719" };
	//std::string passports[] = { "pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980 hcl:#623a2f " };


	std::string requiredFields[] = { "byr","iyr","eyr","hgt","hcl","ecl","pid" };
	//std::string requiredFields[] = { "byr","iyr","eyr","hgt","hcl","ecl","pid","cid" }; // with the CID as mandatory

	std::string validHairColours[] = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

	const int arraySize = sizeof( passports ) / sizeof( passports[0] );
	const int fieldsArraySize = sizeof( requiredFields ) / sizeof( requiredFields[0] );

    int validPassports = 0;
	
	int counter = 0;

    for ( auto passport : passports )
    {
        int validFields = 0;

		std::cout << counter << std::endl;

        for ( int j = 0; j < passport.size( ); j++ )
        {
            if ( ':' == passport.at( j ) )
            {
                std::string fieldID = { passport.at( j - 3 ), passport.at( j - 2 ), passport.at( j - 1 ) };

				if ( "byr" == fieldID )
				{
					std::cout << "byr" << std::endl;

					if ( j + 1 + 5 < passport.size( ) )
					{
						if ( ' ' == passport.at( j + 5 ) || '"' == passport.at( j + 5 ) )
						{
							int year;

							std::istringstream iss( std::string( { passport.at( j + 1 ), passport.at( j + 2 ), passport.at( j + 3 ), passport.at( j + 4 ) } ) );
							iss >> year;

							if ( year >= 1920 && year <= 2002 )
							{
								validFields++;
								std::cout << "success - byr" << std::endl;
							}
							else
							{
								std::cout << "byr" << std::endl;
							}
						}
					}
				}
				else if ( "iyr" == fieldID )
				{
					std::cout << "iyr" << std::endl;

					if ( j + 1 + 5 < passport.size( ) )
					{
						if ( ' ' == passport.at( j + 5 ) )
						{
							int year;

							std::istringstream iss( std::string( { passport.at( j + 1 ), passport.at( j + 2 ), passport.at( j + 3 ), passport.at( j + 4 ) } ) );
							iss >> year;

							if ( year >= 2010 && year <= 2020 )
							{
								validFields++;
								std::cout << "success - iyr" << std::endl;
							}
							else
							{
								std::cout << "iyr" << std::endl;
							}
						}
					}
				}
				else if ( "eyr" == fieldID )
				{
					std::cout << "eyr" << std::endl;

					if ( j + 1 + 5 < passport.size( ) )
					{
						if ( ' ' == passport.at( j + 5 ) )
						{
							int year;

							std::istringstream iss( std::string( { passport.at( j + 1 ), passport.at( j + 2 ), passport.at( j + 3 ), passport.at( j + 4 ) } ) );
							iss >> year;

							if ( year >= 2020 && year <= 2030 )
							{
								validFields++;
								std::cout << "success - eyr" << std::endl;
							}
							else
							{
								std::cout << "eyr" << std::endl;
							}
						}
					}
				}
				else if ( "hgt" == fieldID )
				{
					std::cout << "hgt" << std::endl;

					if ( j + 1 + 5 < passport.size( ) )
					{
						if ( "cm" == std::string( { passport.at( j + 4 ), passport.at( j + 5 ) } ) )
						{
							int height;

							std::istringstream iss( std::string( { passport.at( j + 1 ), passport.at( j + 2 ), passport.at( j + 3 ) } ) );
							iss >> height;

							if ( height >= 150 && height <= 193 )
							{
								validFields++;
								std::cout << "success - hgt cm" << std::endl;
							}
							else
							{
								std::cout << "hgt" << std::endl;
							}
						}
						else if ( j + 1 + 4 < passport.size( ) )
						{
							if ( "in" == std::string( { passport.at( j + 3 ), passport.at( j + 4 ) } ) )
							{
								int height;

								std::istringstream iss( std::string( { passport.at( j + 1 ), passport.at( j + 2 ) } ) );
								iss >> height;

								if ( height >= 59 && height <= 76 )
								{
									validFields++;
									std::cout << "success - hgt in" << std::endl;
								}
								else
								{
									std::cout << "in" << std::endl;
								}
							}
						}
					}
				}
				else if ( "hcl" == fieldID )
				{
				std::cout << "hcl" << std::endl;

					if ( '#' == passport.at( j + 1 ) )
					{
						if ( j + 1 + 6 < passport.size( ) )
						{
							bool failed = false;

							for ( int i = 1; i <= 6; i++ )
							{
								if ( !( ( int( passport.at( j + 1 + i ) ) >= 48 && int( passport.at( j + 1 + i ) ) <= 57 )
									|| ( int( passport.at( j + 1 + i ) ) >= 65 && int( passport.at( j + 1 + i ) ) <= 90 )
									|| ( int( passport.at( j + 1 + i ) ) >= 97 && int( passport.at( j + 1 + i ) ) <= 122 ) ) )
								{
									failed = true;
								}
							}

							if ( !failed )
							{
								validFields++;
								std::cout << "success - hcl" << std::endl;
							}
							else
							{
								std::cout << "hcl" << std::endl;
							}
						}
						else
						{
							if ( ' ' == passport.at( j + 8 ) )
							{
								bool failed = false;

								for ( int i = 1; i <= 6; i++ )
								{
									if ( !( ( int( passport.at( j + 1 + i ) ) >= 48 && int( passport.at( j + 1 + i ) ) <= 57 )
										|| ( int( passport.at( j + 1 + i ) ) >= 65 && int( passport.at( j + 1 + i ) ) <= 90 )
										|| ( int( passport.at( j + 1 + i ) ) >= 97 && int( passport.at( j + 1 + i ) ) <= 122 ) ) )
									{
										failed = true;
									}
								}

								if ( !failed )
								{
									validFields++;
									std::cout << "success - hcl" << std::endl;
								}
								else
								{
									std::cout << "hcl" << std::endl;
								}
							}
						}
					}
				}
				else if ( "ecl" == fieldID )
				{

				std::cout << "ecl" << std::endl;

					if ( j + 1 + 4 < passport.size( ) )
					{
						if ( ' ' == passport.at( j + 4 ) )
						{
							const std::string colourCode( { passport.at( j + 1 ), passport.at( j + 2 ), passport.at( j + 3 ) } );

							for ( auto id : validHairColours )
							{
								//std::cout << colourCode << " / " << id << std::endl;
								if ( colourCode == id )
								{
									std::cout << "success - ecl" << std::endl;
									validFields++;

									//std::cout << "valid" << std::endl;
								}
								else
								{
									//std::cout << "ecl" << std::endl;
								}
							}
						}
					}
				}
				else if ( "pid" == fieldID )
				{

				std::cout << "pid" << std::endl;

					if ( j + 1 + 10 < passport.size( ) )
					{
						if ( ' ' == passport.at( j + 10 ) )
						{
							bool failed = false;

							for ( int i = 1; i <= 9; i++ )
							{
								if ( !( int( passport.at( j + i ) ) >= 48 && int( passport.at( j + i ) ) <= 57 ) )
								{
									failed = true;
								}
							}

							if ( !failed )
							{
								validFields++;
								std::cout << "success - pid" << std::endl;

							}
							else
							{
								std::cout << "pid" << std::endl;
							}
						}
					}
				}

				
				
				//pid( Passport ID ) - a nine - digit number, including leading zeroes.

                /*for ( auto field : requiredFields )
                {
                    if ( field == fieldID )
                    {
                        validFields++;
                    }
                }*/
            }
        }

		std::cout << "Valid fields: " << validFields << std::endl;

        if ( validFields >= fieldsArraySize )
        {
            validPassports++;
        }

		counter++;
    }

    const int invalidPassports = arraySize - validPassports;

    std::cout << "There are " << validPassports << " valid passports and " << invalidPassports << " invalid passports" << std::endl;

    return 0;
}