CREATE TABLE pas_info (
    pas_info_key VARCHAR PRIMARY KEY,
    pas_info_value VARCHAR NOT NULL
);

INSERT INTO pas_info (
    pas_info_key,
    pas_info_value
) VALUES (
    "pas_initialized",
    "1"
);

INSERT INTO pas_info (
    pas_info_key,
    pas_info_value
) VALUES (
    "pas_http_bind_address",
    "0.0.0.0"
);

INSERT INTO pas_info (
    pas_info_key,
    pas_info_value
) VALUES (
    "pas_http_bind_port",
    "7348"
);