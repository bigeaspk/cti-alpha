while {true} do {

_objList = [] call BSPK_fnc_secActiveCheck;

_activeObj = (_objList select 0);
_inactiveObj = (_objList select 1);

{
_markerZone = (str(_x) + "_zone");
_markerZone setMarkerAlpha 1;
} forEach _activeObj;

{
_markerZone = (str(_x) + "_zone");
_markerZone setMarkerAlpha 0;
} forEach _inactiveObj;

sleep 1;

};