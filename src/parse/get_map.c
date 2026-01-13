#include "head.h"

t_map	get_map(void)
{
	t_map	new_map;

	new_map = (t_map) {
		.amblight = (t_amblight) {
			.ratio = 0.2,
			.color = color(255, 255, 255)
		},
		.camera = (t_camera) {
			.position = point(-50.0, 0.0, 20.0),
			.orientation = vector(0.0, 0.0, 1.0),
			.fov = 70,
		},
		.light = &(t_light) {
			.position = point(-40.0, 50.0, 0.0),
			.brightness = 0.6,
			.color = color(10, 0, 255)
		},
		.object = &(t_object) {
			.type = SPHERE,
			.position = point(0.0, 0.0, 20.6),
			.color = color(10, 0, 255),
			.options = &(t_sphere) {
				.diameter = 12.6,
			},
		}
	};
	return (new_map);
}
