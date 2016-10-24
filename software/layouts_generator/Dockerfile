FROM python:3.5-alpine
MAINTAINER Fabien Dubosson <fabien.dubosson@gmail.com>

RUN apk add --no-cache inkscape

COPY ./ /usr/src/app/
WORKDIR /usr/src/app/

RUN pip install -r requirements.txt

EXPOSE 8000
ENTRYPOINT ["python"]
CMD ["service.py"]
