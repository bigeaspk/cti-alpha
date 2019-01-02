_allTriggers = allMissionObjects "EmptyDetector";

_objTriggers = [];

//Get objective list

{
	_string = str(_x) splitString "_";
	if ((_string select 0) == "objective") then {
		_objTriggers pushBack _x;
	};
} forEach _allTriggers;

_activeObj = [];
_inactiveObj = [];

{
	_distance = (player distance2D _x);
	if (_distance <= 1500) then {
		_activeObj pushBack _x;
	};
} forEach _objTriggers;

{
	_distance = (player distance2D _x);
	if (_distance > 2000) then {
		_inactiveObj pushBack _x;
	};
} forEach _objTriggers;

[_activeObj,_inactiveObj];