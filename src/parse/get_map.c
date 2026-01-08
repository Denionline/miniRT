#include "head.h"

t_map	get_map(void)
{
	t_map	new_map;

	new_map = (t_map) {
		.amblight = (t_amblight) {
			.ratio = 0.2,
			.color = (t_vector) {
				.x = 255,
				.y = 255,
				.z = 255,
			},
		},
		.camera = (t_camera) {
			.position = (t_vector) {
				.x = -50.0,
				.y = 0,
				.z = 20,
			},
			.orientation = (t_vector) {
				.x = 0.0,
				.y = 0.0,
				.z = 1.0,
			},
			.fov = 70,
		},
		.light = &(t_light) {
			.position = (t_vector) {
				.x = -40.0,
				.y = 50.0,
				.z = 0.0,
			},
			.brightness = 0.6,
			.color = (t_vector) {
				.x = 10,
				.y = 0,
				.z = 255,
			},
		},
		.object = &(t_object) {
			.type = SPHERE,
			.position = (t_vector) {
				.x = 0.0,
				.y = 0.0,
				.z = 20.6,
			},
			.color = (t_vector) {
				.x = 10,
				.z = 0,
				.z = 255,
			},
			.options = &(t_sphere) {
				.diameter = 12.6,
			},
		}
	};
	return (new_map);
}
