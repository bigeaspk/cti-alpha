_allTriggers = allMissionObjects "EmptyDetector";

_objTriggers = [];

//Get objective list

{
_string = str(_x) splitString "_";
if ((_string select 0) == "objective") then {
		_objTriggers pushBack _x;
	};
} forEach _allTriggers;


activeZones = []
{

} forEach _objTriggers;